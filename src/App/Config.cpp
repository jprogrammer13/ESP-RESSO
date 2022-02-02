#include <Arduino.h>
#include <App.h>
#include <App/Config.h>

Config::Config(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    t_start = millis();
}

void Config::draw()
{
    // BOOTLOGO
    display->firstPage();
    do
    {
        display->drawXBMP(42, 12, 44, 44, logo);

    } while (display->nextPage());

    // INITIAL WIFI CONFIG AND CONNECT
    Serial.println("Connecting WiFi");

    String msg = "{\"action\":\"send\",\"data\":{\"wifi_mode\":\"WIFI_STA\",\"ssid\":\"" WIFI_SSID "\",\"psw\":\"" WIFI_PSWD "\"}}";
    // ONCE WIFI CONNECTED, CONNECT MQTT
    if (strcmp(sysServices->sendMsg("ServiceWiFi", msg).c_str(), "{\"data\":1}") == 0)
    {
        Serial.println("WiFi Connected!");
        Serial.println("Connecting MQTT");

        msg = "{\"action\":\"send\",\"data\":{\"action\":\"connect\"}}";
        Serial.println(msg);
        if (strcmp(sysServices->sendMsg("ServiceMQTT", msg).c_str(), "{\"data\":1}") == 0)
        {
            Serial.println("MQTT Connected!");

            // System is connected
            sysUi->setUi("Home");
        }
    }
}