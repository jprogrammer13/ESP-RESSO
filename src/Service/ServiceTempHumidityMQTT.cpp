#include <Arduino.h>
#include <Service/ServiceTempHumidityMQTT.h>

ServiceTempHumidityMQTT::ServiceTempHumidityMQTT(){};

ServiceTempHumidityMQTT::ServiceTempHumidityMQTT(WiFiClass *_wifi, Adafruit_MQTT_Client *_mqtt) : Service(_wifi, _mqtt)
{
    t_start = millis();
    this->mqtt->subscribe(&temp_contoll);
}

String ServiceTempHumidityMQTT::sendMsg(String msg)
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
        float data_temperature = doc["data"]["temperature"]; 
        int data_humidity = doc["data"]["humidity"];         
        int data_temp_select = doc["data"]["temp_select"];         
        int data_state = doc["data"]["state"];         

        temp_topic.publish(data_temperature);
        humidiy_topic.publish(data_humidity);
        temp_selected_topic.publish(data_temp_select);
        state_topic.publish(data_state);
        responseMsg = "{\"data\":1}";
    }
    else if (strcmp(action, "get") == 0)
    {
        Adafruit_MQTT_Subscribe *subscription;
        // Serial.println("GETTING LATEST TEMPERATURE CONTOLL");
        while ((subscription = this->mqtt->readSubscription(2000)))
        {
            if (subscription == &temp_contoll)
            {
                responseMsg = "{\"data\": { \"temperature_contoll\":" + String((char *)temp_contoll.lastread) + "}}";
            }
            else
            {
                responseMsg = "error";
            }
        }
    }

    return responseMsg;
}