#include <Arduino.h>
#include <App.h>
#include <App/Config.h>

Config::Config(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    t_start = millis();
}

void Config::draw()
{
    String msg = "{\"action\":\"send\",\"data\":{\"wifi_mode\":\"WIFI_STA\",\"ssid\":\"Riky Hotspot\",\"psw\":\"Riccardo_13\"}}";
    display->firstPage();
    do
    {
        display->drawCircle(64, 32, 20);
    } while (display->nextPage());

    if (strcmp(sysServices->sendMsg("ServiceWiFi", msg).c_str(), "{\"data\":1}") == 0)
    {
        // System is connected
        sysUi->setUi("Home");
    }
}