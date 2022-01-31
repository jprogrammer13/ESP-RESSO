#include <Arduino.h>
#include <Service/ServiceTempLog.h>

ServiceTempLog::ServiceTempLog(){

};

String ServiceTempLog::sendMsg(String msg)
{
    String responseMsg;
    DynamicJsonDocument doc(128);

    DeserializationError error = deserializeJson(doc, msg);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return "error";
    }

    const char *action = doc["action"];
    if (strcmp(action, "send") == 0)
    {
        int data_temperature = doc["data"]["temperature"];
        unsigned long data_time = doc["data"]["time"];
        Serial.println(String(data_temperature)+":"+String(data_time));
        temp_logs.insert(std::pair<int, unsigned long>(data_temperature, data_time));
        responseMsg = "{\"data:\"1}";
    }
    else
    {
        responseMsg = "error";
    }

    return responseMsg;
}