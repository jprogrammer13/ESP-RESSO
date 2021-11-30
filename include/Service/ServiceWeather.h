#include <Arduino.h>
#include <Service.h>

class ServiceWeather : public Service
{
public:
    ServiceWeather();
    ServiceWeather(WiFiClass *_wifi);
    String sendMsg(String msg);

private:
    HTTPClient http;
    String API_key;
    unsigned long t_start;
};