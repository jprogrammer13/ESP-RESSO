#include <Arduino.h>
#include <App.h>
#include <App/Home.h>

Home::Home(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    t_start = millis();
    temp_current = 21.5;
    temp_selected = temp_current;
    tmp_temp = temp_current;
    humidity = 70;

    hour = 15;
    minute = 18;
    day_week = "Mon";
    day = 32;
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
        display->drawUTF8(14, 43, ("h:"+String(humidity) + "%").c_str());

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

        break;
    case A_BACK_LONG:

        break;
    }
}

void Home::background() {}