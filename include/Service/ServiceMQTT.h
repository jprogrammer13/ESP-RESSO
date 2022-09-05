#include <Arduino.h>
#include <Service.h>

class ServiceMQTT : public Service
{
public:
    ServiceMQTT();
    ServiceMQTT(WiFiClass *_wifi,Adafruit_MQTT_Client *_mqtt);
    String sendMsg(String msg);

private:
    unsigned long t_start;
};