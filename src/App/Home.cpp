#include <Arduino.h>
#include <App.h>
#include <App/Home.h>

Home::Home(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    radius = 6;
}

void Home::draw()
{
    display->firstPage();
    do
    {
        display->setFont(u8g2_font_ncenB14_tr);
        display->setCursor(30, 45);
        display->print("Hell   :)");
        display->drawCircle(75, 38, radius);
    } while (display->nextPage());

    switch (navigation->get_action())
    {
    case A_DOWN:
        radius++;
        break;
    case A_UP:
        radius--;
        break;
    case A_SELECT:
        radius = 6;
        break;
    case A_BACK_LONG:
        sysUi->setUi("Test");
        break;
    }
}