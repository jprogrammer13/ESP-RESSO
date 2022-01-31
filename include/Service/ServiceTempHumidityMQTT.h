#include <Arduino.h>
#include <Service.h>

class ServiceTempHumidityMQTT : public Service
{
public:
    ServiceTempHumidityMQTT();
    ServiceTempHumidityMQTT(WiFiClass *_wifi, Adafruit_MQTT_Client *_mqtt);
    String sendMsg(String msg);

private:
    Adafruit_MQTT_Publish temp_topic = Adafruit_MQTT_Publish(this->mqtt, "Riccardo136/feeds/temperature");
    Adafruit_MQTT_Publish humidiy_topic = Adafruit_MQTT_Publish(this->mqtt, "Riccardo136/feeds/humidity");
    Adafruit_MQTT_Publish temp_selected_topic = Adafruit_MQTT_Publish(this->mqtt, "Riccardo136/feeds/temperature_selected");
    Adafruit_MQTT_Publish state_topic = Adafruit_MQTT_Publish(this->mqtt, "Riccardo136/feeds/state");
    Adafruit_MQTT_Subscribe temp_contoll = Adafruit_MQTT_Subscribe(this->mqtt, "Riccardo136/feeds/temperature_contoll");

    unsigned long t_start;
};