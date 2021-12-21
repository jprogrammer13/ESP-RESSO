#include <Arduino.h>
#include <App.h>
#include <App/Home.h>

Home::Home(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    t_start = millis();
    t_time = millis();
    t_temp_check = millis();

    temp_current = 0;
    humidity = 0;

    hour = 0;
    minute = 0;
    day_week = "";
    day = 0;

    first_time = 1;

    temp_selected = 20;
    tmp_temp = temp_current;
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

        // SEZIONE DI SINISTRA

        // #### SEZIONE TEMP CORRENTE E SELEZIONATA ##########

        display->setFont(u8g2_font_open_iconic_weather_2x_t);
        display->drawGlyph(68, 46, 0x0045);

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
            sysUi->setUi("Test");
        break;
    case A_BACK_LONG:

        break;
    }
}

void Home::background()
{

    if (first_time)
    {
        String msg = "{\"action\":\"send\",\"data\":{\"wifi_mode\":\"WIFI_STA\",\"ssid\":\"Riky Hotspot\",\"psw\":\"Riccardo_13\"}}";
        Serial.println(sysServices->sendMsg("ServiceWiFi", msg));
    }

    if (millis() - t_start > 10000 || first_time)
    {
        t_start = millis();
        this->get_temp_sensor();
    }

    if (millis() - t_time > 30000 || first_time)
    {
        t_time = millis();
        this->get_time_service();
    }

    first_time = 0;

    if (millis() - t_temp_check > 60000)
    {
        t_temp_check = millis();
        if (temp_current < temp_selected + 0.5)
        {
            this->set_relay(1);
        }
        else
        {
            this->set_relay(0);
        }
    }
}

void Home::get_temp_sensor()
{

    String msg = "{\"action\":\"get\",\"data\":\"all\"}";
    String response = sysServices->sendMsg("ServiceTempHumidity", msg);
    DynamicJsonDocument doc(96);

    DeserializationError error = deserializeJson(doc, response);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
    }

    this->temp_current = doc["data"]["temperature"];
    this->humidity = doc["data"]["humidity"];
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

void Home::set_relay(bool state)
{
    String msg = "{\"action\":\"send\",\"data\":{\"status\":" + String(state) + "}}";
    sysServices->sendMsg("ServiceRelay", msg);
}