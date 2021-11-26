#include <Arduino.h>
#include <App.h>

class Home : public App
{

public:
    Home();
    Home(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService);
    void draw();
    void draw_widget(){};
    void background()
    {
        String msg;

        Serial.println("---SERVICE-TEST--------------");
        msg = "{\"action\":\"get\",\"data\":\"all\"}";
        Serial.println(sysServices->sendMsg("ServiceTempHumidity", msg));

        msg = "{\"action\":\"get\",\"data\":\"temperature\"}";
        Serial.println(sysServices->sendMsg("ServiceTempHumidity", msg));

        msg = "{\"action\":\"get\",\"data\":\"humidity\"}";
        Serial.println(sysServices->sendMsg("ServiceTempHumidity", msg));
        Serial.println("-----------------------------");
    };

private:
    int radius;
};
