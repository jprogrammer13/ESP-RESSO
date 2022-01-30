#include <Arduino.h>
#include <Service/ServiceTempHumidityMQTT.h>

ServiceTempHumidityMQTT::ServiceTempHumidityMQTT(){};

ServiceTempHumidityMQTT::ServiceTempHumidityMQTT(WiFiClass *_wifi, Adafruit_MQTT_Client *_mqtt) : Service(_wifi, _mqtt)
{
    t_start = millis();
}

String ServiceTempHumidityMQTT::sendMsg(String msg)
{
    String responseMsg;

    Serial.println("Sending test data");
    if (!test.publish("Ciao"))
    {
        Serial.println(F("Failed"));
    }
    else
    {
        Serial.println(F("OK!"));
    }

    return responseMsg;
}