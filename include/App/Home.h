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
        if (millis() - t_start > 10000)
        {
            t_start = millis();
            String msg;

            // Serial.println("---SERVICE-TEST--------------");
            msg = "{\"action\":\"get\",\"data\":\"all\"}";
            Serial.println(sysServices->sendMsg("ServiceTempHumidity", msg));

            // msg = "{\"action\":\"get\",\"data\":\"temperature\"}";
            // Serial.println(sysServices->sendMsg("ServiceTempHumidity", msg));

            // msg = "{\"action\":\"get\",\"data\":\"humidity\"}";
            // Serial.println(sysServices->sendMsg("ServiceTempHumidity", msg));
            // Serial.println("-----------------------------");
            msg = "{\"action\":\"get\",\"data\":{\"city\":\"Trento\",\"n_day\":2}}";
            Serial.println(sysServices->sendMsg("ServiceWeather", msg));

            msg = "{\"action\":\"get\",\"data\":{\"gmt_offset\":3600,\"light_offest\":3600}}";
            Serial.println(sysServices->sendMsg("ServiceTime", msg));
        }
    };

private:
    int radius;
    int t_start = millis();
};
