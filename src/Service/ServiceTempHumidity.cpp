#include <Arduino.h>
#include <Service/ServiceTempHumidity.h>

ServiceTempHumidity::ServiceTempHumidity()
{
    tempSensor.begin();
    t_start = millis();
};

String ServiceTempHumidity::sendMsg(String msg)
{
    String responseMsg;
    // expected "action":"get"
    // data can be:
    /**
     * @all: get temperature and humidity
     * @temperature: get tempreature
     * @humidity: get humidity
     */
    // String input;

    // TO READ THE INPUT MSG
    StaticJsonDocument<96> doc; // can change in other service

    DeserializationError error = deserializeJson(doc, msg);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return "error";
    }

    const char *action = doc["action"];
    const char *data = doc["data"];

    // timer to respect the sensor reading time
    if (millis() - t_start > 2000)
    {
        t_start = millis();
        temperature = tempSensor.readTemperature();
        humidity = tempSensor.readHumidity();
    }

    // TO RESPOND

    StaticJsonDocument<48> response;

    JsonObject data_resp = response.createNestedObject("data");

    if (strcmp(action, "get") == 0)
    {
        if (strcmp(data, "all") == 0)
        {
            data_resp["temperature"] = temperature;
            data_resp["humidity"] = humidity;
        }
        if (strcmp(data, "temperature") == 0)
        {
            data_resp["temperature"] = temperature;
        }
        if (strcmp(data, "humidity") == 0)
        {
            data_resp["humidity"] = humidity;
        }
        serializeJson(response, responseMsg);
    }
    else
    {
        responseMsg = "error";
    }

    return responseMsg;
}