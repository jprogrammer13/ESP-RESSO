#include <Arduino.h>
#include <Service.h>

class ServiceControlMQTT : public Service
{
public:
    ServiceControlMQTT();
    ServiceControlMQTT(WiFiClass *_wifi, Adafruit_MQTT_Client *_mqtt);
    String sendMsg(String msg);

private:
    Adafruit_MQTT_Publish control_topic = Adafruit_MQTT_Publish(this->mqtt, ADAFRUIT_USERNAME "/feeds/device_control");
};