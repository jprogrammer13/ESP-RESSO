#include <Arduino.h>
#include <App.h>
#include <App/Weather.h>

Weather::Weather(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    first_time = true;
    city = CITY;
    no_day = 1;
    y_position = 0;
    weather_icon = 0x00f0;
}

void Weather::draw()
{
    if (first_time)
    {
        // CHIAMATA AI DATI
        msg = "{\"action\":\"get\",\"data\":{\"city\":\"" + String(this->city) + "\",\"n_day\":" + String(this->no_day) + "}}";

        response = sysServices->sendMsg("ServiceWeather", msg);

        DynamicJsonDocument doc(512);

        DeserializationError error = deserializeJson(doc, response);

        if (!error)
        {
            JsonObject data = doc["data"];

            data_temp_min = data["temp_min"][0];
            data_temp_max = data["temp_max"][0];
            data_humidity = data["humidity"][0];
            data_weather_main = data["weather"][0];
            data_weather_description = data["weather"][1];
            Serial.println("[Weather APP]: data recived!");

            //stampa DATA,TEMP_MIN,TEMP_MAX,HUMIDITY,WEATHER
            // Serial.println("TEMP_MIN: " + String(data_temp_min));
            // Serial.println("TEMP_MAX: " + String(data_temp_max));
            // Serial.println("HUMIDITY: " + String(data_humidity));
            // Serial.println("WEATHER: " + String(data_weather_main));
            // Serial.println("WEATHER DESC: " + String(data_weather_description));

            for (int i = 0; i < 6; i++)
            {
                if (strcmp(data_weather_main, weather_descriptions[i].c_str()) == 0)
                {
                    this->weather_icon = this->weather_icons[i];
                    break;
                }
                else
                {
                    this->weather_icon = 0x00f0;
                }
            }

            first_time = false;
        }
        else
        {
            first_time = true;
        }
    }
    display->firstPage();
    do
    {
        display->setFont(u8g2_font_fur17_tf);
        display->drawStr(5, y_position + 22, city.c_str());
        display->setFont(u8g2_font_open_iconic_all_4x_t);
        display->drawGlyph(5, y_position + 60, this->weather_icon);
        display->setFont(u8g2_font_fur14_tf);
        display->drawStr(45, y_position + 40, (String(this->data_temp_max) + String(" C*")).c_str());
        display->setFont(u8g2_font_fur11_tf);
        display->drawStr(55, y_position + 57, (String(this->data_temp_min) + String(" C*")).c_str());

        display->setFont(u8g2_font_fur11_tf);
        display->drawStr(5, y_position + 75, (String("H:") + String(this->data_humidity) + String("%")).c_str());
        display->drawStr(5, y_position + 83, "-------------------");
        display->setFont(u8g2_font_6x10_tf);
        display->setCursor(5,y_position + 95);
        display->println(this->data_weather_description);
        // display->println(5, y_position + 90, (String(this->data_weather_description)).c_str());

    } while (display->nextPage());

    switch (navigation->get_action())
    {
    case A_BACK:
        first_time = true;
        sysUi->setUi("Menu");
        break;
    case A_DOWN:
        if (y_position > -64)
        {
            y_position -= 4;
        }
        break;
    case A_UP:
        if (y_position < 0)
        {
            y_position += 4;
        }
        break;
    case A_SELECT:
        y_position = 0;
        break;
    }
}

// Creati un avariabile che firsttime che serve solo quando apri la app
// Una volta che lhai usata la metti a zero e la rimetti a 1 solo quando schiacci back
