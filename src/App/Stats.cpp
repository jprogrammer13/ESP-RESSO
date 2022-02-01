#include <Arduino.h>
#include <App.h>
#include <App/Stats.h>

Stats::Stats(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
}

void Stats::draw()
{
    display->firstPage();
    do
    {
        display->setFont(u8g2_font_7x14_tf);
        display->setCursor(15, 40);
        display->print("STATS APP");
    } while (display->nextPage());

    switch (navigation->get_action())
    {
    case A_BACK:
        sysUi->setUi("Menu");
        break;
    }
}