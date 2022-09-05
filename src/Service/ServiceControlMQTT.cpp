#include <Arduino.h>
#include <Service/ServiceControlMQTT.h>

ServiceControlMQTT::ServiceControlMQTT(){};

ServiceControlMQTT::ServiceControlMQTT(WiFiClass *_wifi, Adafruit_MQTT_Client *_mqtt) : Service(_wifi, _mqtt)
{
}

String ServiceControlMQTT::sendMsg(String msg)
{
    String responseMsg;

    DynamicJsonDocument doc(256);

    DeserializationError error = deserializeJson(doc, msg);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return "error";
    }

    const char *action = doc["action"]; // "send"

    if (strcmp(action, "send") == 0)
    {
        const char *data_control = doc["data"]["control"];

        control_topic.publish(data_control);
        responseMsg = "{\"data\":1}";
    }
    else
    {
        responseMsg = "error";
    }

    return responseMsg;
}