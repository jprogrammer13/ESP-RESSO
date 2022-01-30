#include <Arduino.h>
#include <App.h>
#include <App/Test.h>

Test::Test(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    numero = 20;
}

void Test::draw()
{
    display->firstPage();
    do
    {
        display->drawCircle(64, 32, numero);
    } while (display->nextPage());

    switch (navigation->get_action())
    {
    case A_BACK:
        sysUi->setUi("Menu");
        break;
    case A_UP:
        numero++;
        break;
    case A_DOWN:
        numero--;
        break;
    case A_SELECT:
        numero = 20;
        break;
    }
}