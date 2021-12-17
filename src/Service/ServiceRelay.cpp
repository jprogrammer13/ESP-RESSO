#include <Arduino.h>
#include <Service/ServiceRelay.h>

ServiceRelay::ServiceRelay()
{
    this->relay_pin = 26;
    pinMode(this->relay_pin, OUTPUT);
    this->status = 0;
};

String ServiceRelay::sendMsg(String msg)
{
    String responseMsg;
    // expected "action":"send"
    // data can be:
    /**
     * @status: set status of relay
     */

    DynamicJsonDocument doc(96);
    DeserializationError error = deserializeJson(doc, msg);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return "error";
    }

    const char *action = doc["action"];      // "send"
    int data_status = doc["data"]["status"]; // 1

    if (strcmp(action, "send") == 0)
    {
        DynamicJsonDocument response(32);
        this->status = data_status;
        digitalWrite(this->relay_pin, this->status);
        response["data"]["status"] = this->status;
        serializeJson(response, responseMsg);
    }
    else
    {
        responseMsg = "error";
    }

    return responseMsg;
}