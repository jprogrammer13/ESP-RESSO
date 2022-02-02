#include <Arduino.h>
#include <Service.h>

class ServiceFinance : public Service
{
public:
    ServiceFinance();
    ServiceFinance(WiFiClass *_wifi);
    String sendMsg(String msg);

private:
    HTTPClient http;
    String API_key;
};