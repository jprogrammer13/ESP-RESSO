#include <Arduino.h>
#include <Service.h>

class ServiceWiFi : public Service
{
public:
    ServiceWiFi();
    ServiceWiFi(WiFiClass *_wifi);
    String sendMsg(String msg);

private:
    unsigned long t_start;
};