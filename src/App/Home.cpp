#include <Arduino.h>
#include <App.h>
#include <App/Home.h>

Home::Home(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    t_sensor = millis();
    t_mqtt_pub = millis();
    t_time = millis();
    t_weather = millis();
    t_temp_check = millis();
    t_relay_check = millis();

    temp_current = 0;
    humidity = 0;

    weather_icon = 0x00f0;

    hour = 0;
    minute = 0;
    day_week = "";
    day = 0;

    first_time = 1;

    temp_selected = 20;
    tmp_temp = temp_current;

    thermostat_on = true;
}

void Home::draw()
{
    display->firstPage();
    do
    {
        display->setFontMode(1);
        display->setDrawColor(1);

        // SEZIONE DI DESTRA

        // #### SEZIONE TEMPO ##########
        display->drawBox(55, 0, 73, 64);
        display->setFont(u8g2_font_fub20_tn);
        display->setDrawColor(0);
        display->drawStr(58, 24, (((hour < 10) ? ("0" + String(hour)) : String(hour)).c_str()));
        display->drawStr(93, 47, (((minute < 10) ? ("0" + String(minute)) : String(minute)).c_str()));

        // #### SEZIONE GIRONO ##########

        display->setFont(u8g2_font_etl16thai_t);
        display->drawStr(101, 14, day_week.c_str());
        display->drawStr(109, 26, (((day < 10) ? ("0" + String(day)) : String(day)).c_str()));

        // #### SEZIONE METEO ##########
        display->setFont(u8g2_font_open_iconic_all_2x_t);
        display->drawGlyph(68, 46, weather_icon);

        // SEZIONE DI SINISTRA

        // #### SEZIONE TEMP CORRENTE E SELEZIONATA ##########

        display->setDrawColor(1);
        display->setFont(u8g2_font_fur20_tn);

        if (millis() - t_tmp_start > 5000)
        {
            tmp_temp = temp_current;
        }
        else
        {
            tmp_temp = temp_selected;
        }
        display->drawStr(5, 24, (((int(tmp_temp) < 10) ? ("0" + String(int(tmp_temp))) : String(int(tmp_temp))).c_str()));
        display->drawStr(33, 24, ".");
        display->setFont(u8g2_font_fur14_tn);
        display->drawStr(40, 24, (((fmod(tmp_temp, 1) > 0 ? String("5") : String("0"))).c_str()));

        // #### SEZIONE UMIDITÀ ##########

        display->drawRBox(8, 33, 39, 12, 5);
        display->setDrawColor(0);
        display->setFont(u8g2_font_courB08_tf);
        display->drawUTF8(14, 43, ("h:" + String(humidity) + "%").c_str());

        display->setDrawColor(1);

        // SEZIONE TACCHETTE
        if (thermostat_on)
        {
            display->setDrawColor(0);
            display->drawBox(0, 50, 128, 14);

            display->setDrawColor(1);

            for (int i = 2; i < 128; i += 3)
            {
                display->drawLine(i, 52, i, 62);
            }

            int temp_x = map(temp_current, 0, 40, 0, 128);
            int temp_sel_x = map(temp_selected, 0, 40, 0, 128);

            display->drawBox(temp_x, 50, 4, 14);
            display->drawBox(temp_sel_x, 50, 2, 14);
        }
        else
        {
            /* code */
            display->drawBox(0, 50, 128, 14);
            display->setFont(u8g2_font_7x14_tf);
            display->setCursor(13, 62);
            display->setDrawColor(0);
            display->print("Thermostat: OFF");
            display->setDrawColor(1);
        }

    } while (display->nextPage());

    switch (navigation->get_action())
    {
    case A_DOWN:
        t_tmp_start = millis();
        if (temp_selected < 40)
        {
            temp_selected += 0.5;
        }
        break;
    case A_UP:
        t_tmp_start = millis();
        if (temp_selected > 0.5)
        {
            temp_selected -= 0.5;
        }

        break;
    case A_SELECT:
        sysUi->setUi("Menu");
        break;
    case A_SELECT_LONG:
        thermostat_on = !thermostat_on;
        if (thermostat_on)
        {
            temp_selected = 20;
        }
        else
        {
            temp_selected = 10;
        }
    }
}

void Home::background()
{
    // GET TIME
    if (millis() - t_time > 30000 || first_time)
    {
        t_time = millis();
        Serial.println("Getting time value");
        this->get_time_service();
    }

    // GET WEATHER
    if (millis() - t_weather > 1800000 || first_time)
    {
        t_weather = millis();
        Serial.println("Getting weather value");
        this->get_weather_service();
    }

    // GET SENSOR VALUES
    if (millis() - t_sensor > 10000 || first_time)
    {
        t_sensor = millis();
        Serial.println("Getting DHT11 sensor values");
        this->get_temp_sensor();
        if (first_time)
        {
            // SETTING STARTING TEMPERATURE
            temp_cur_check = this->temp_current;
        }
    }

    // PUBLISH MQTT DATA AND READ TEMP_CONTROLL

    if (millis() - t_mqtt_pub > 60000)
    {
        t_mqtt_pub = millis();
        // Verify MQTT connection
        Serial.println("Getting MQTT connection status");

        String msg = "{\"action\":\"send\",\"data\":{\"action\":\"connect\"}}";
        if (strcmp(sysServices->sendMsg("ServiceMQTT", msg).c_str(), "{\"data\":1}") == 0)
        {
            Serial.println("Verifying temperature_control msg from MQTT");

            msg = "{\"action\":\"get\"}";
            String temp_control_msg = sysServices->sendMsg("ServiceTempHumidityMQTT", msg);

            DynamicJsonDocument doc(96);

            DeserializationError error = deserializeJson(doc, temp_control_msg);

            if (!error)
            {
                // GET THE MQTT SELECTED TEMPERATURE
                temp_selected = doc["data"]["temperature_contoll"];
                Serial.println("New temperature setted: " + String(temp_selected));
                if (thermostat_on && temp_selected < 15)
                {
                    thermostat_on = false;
                    Serial.println("Thermostat remotely turned off");
                }
                else if (!thermostat_on)
                {
                    thermostat_on = true;
                    Serial.println("Thermostat remotely turned on");
                }
            }

            Serial.println("Sending temperature and humidity to MQTT");

            // SENDING TEMPERATURE AND HUMIDITY TO MQTT MASTER
            msg = "{\"action\":\"send\",\"data\":{\"temperature\":" + String(this->temp_current) + ",\"humidity\":" + String(humidity) + ",\"temp_select\":" + String(temp_selected) + ",\"state\":" + String(thermostat_on) + "}}";
            sysServices->sendMsg("ServiceTempHumidityMQTT", msg);
        }
    }

    if (millis() - t_relay_check > 60000)
    {
        t_relay_check = millis();
        if (temp_current < temp_selected + 0.2)
        {
            this->set_relay(1);
        }
        else
        {
            this->set_relay(0);
        }
    }

    // DISABLE FIRST TIME FUNCTIONS
    first_time = 0;
}

void Home::get_temp_sensor()
{

    String msg = "{\"action\":\"get\",\"data\":\"all\"}";
    String response = sysServices->sendMsg("ServiceTempHumidity", msg);
    DynamicJsonDocument doc(96);

    DeserializationError error = deserializeJson(doc, response);

    if (!error)
    {
        this->temp_current = doc["data"]["temperature"];
        this->humidity = doc["data"]["humidity"];
        Serial.println("Temp: " + String(temp_current));
        Serial.println("Humidity: " + String(humidity));
    }
}

void Home::get_time_service()
{
    String msg = "{\"action\":\"get\",\"data\":{\"gmt_offset\":3600,\"light_offest\":3600}}";
    String response = sysServices->sendMsg("ServiceTime", msg);

    DynamicJsonDocument doc(256);

    DeserializationError error = deserializeJson(doc, response);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
    }

    JsonObject data = doc["data"];
    this->day_week = data["day_name"].as<String>().substring(0, 3);
    this->day = data["day"];
    this->hour = data["hour"];
    this->minute = data["minute"];
}

void Home::get_weather_service()
{
    String msg = "{\"action\":\"get\",\"data\":{\"city\":\"Verona\",\"n_day\":1}}";
    String response = sysServices->sendMsg("ServiceWeather", msg);
    Serial.println(response);

    DynamicJsonDocument doc(512);

    DeserializationError error = deserializeJson(doc, response);

    if (!error)
    {
        JsonObject data = doc["data"];
        const char *data_weather_0 = data["weather"][0];

        for (int i = 0; i < 6; i++)
        {
            if (strcmp(data_weather_0, weather_descriptions[i].c_str()) == 0)
            {
                this->weather_icon = this->weather_icons[i];
                break;
            }
            else
            {
                this->weather_icon = 0x00f0;
            }
        }
    }
    // Serial.println(response);
}

void Home::set_relay(bool state)
{
    String msg = "{\"action\":\"send\",\"data\":{\"status\":" + String(state) + "}}";
    sysServices->sendMsg("ServiceRelay", msg);
}