#include <Arduino.h>
#include <App.h>
#include <App/Home.h>

Home::Home(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{

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

        // display->drawDithering(0, 0, 128, 64, 75, 1);
        display->drawBox(55, 0, 73, 64);
        display->setFont(u8g2_font_7x14B_tf);
        // display->drawRBox(3, 45, 35, 14, 7);
        display->setDrawColor(0);
        display->setFont(u8g2_font_helvR24_te);
        display->drawStr(60, 28, (((hour < 10) ? ("0" + String(hour)) : String(hour)).c_str()));
        // display->drawStr(90, 58, (((minute < 10) ? ("0" + String(minute)) : String(minute)).c_str()));
        display->setFont(u8g2_font_7x14B_tf);

        display->drawStr(105, 13, day_week.c_str());
        display->drawStr(112, 26, (((day < 10) ? ("0" + String(day)) : String(day)).c_str()));

        display->drawBox(0, 50, 128, 14);

        display->setDrawColor(1);

        for (int i = 2; i < 128; i += 3)
        {
            display->drawLine(i, 52, i, 62);
        }

    } while (display->nextPage());

    switch (navigation->get_action())
    {
    case A_DOWN:

        break;
    case A_UP:

        break;
    case A_SELECT:

        break;
    case A_BACK_LONG:

        break;
    }
}

void Home::background() {}