#include <Arduino.h>
#include <Service.h>

class ServiceTempHumidityMQTT : public Service
{
public:
    ServiceTempHumidityMQTT();
    ServiceTempHumidityMQTT(WiFiClass *_wifi, Adafruit_MQTT_Client *_mqtt);
    String sendMsg(String msg);

private:
    Adafruit_MQTT_Publish test = Adafruit_MQTT_Publish(this->mqtt, "Riccardo136/feeds/termostato");
    // Adafruit_MQTT_Publish test = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/test");
    unsigned long t_start;
};