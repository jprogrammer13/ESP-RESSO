#include <Arduino.h>
#include <Service/ServiceTime.h>

ServiceTime::ServiceTime(){};

ServiceTime::ServiceTime(WiFiClass *_wifi) : Service(_wifi)
{
    ntp_server = "0.it.pool.ntp.org";
};

String ServiceTime::sendMsg(String msg)
{
    String responseMsg;
    // expected "action":"get"
    // data can be:
    /** TODO: FIXARE 
     * @gtmoffset: offset for utc time
     */
    StaticJsonDocument<128> doc;

    DeserializationError error = deserializeJson(doc, msg);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return "error";
    }

    const char *action = doc["action"]; // "get"

    int data_gmt_offset = doc["data"]["gmt_offset"];
    int data_light_offest = doc["data"]["light_offest"];

    if (strcmp(action, "get") == 0)
    {
        configTime(data_gmt_offset, data_light_offest, ntp_server.c_str());
        struct tm timeinfo;
        getLocalTime(&timeinfo);
        Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
    }

    return responseMsg;
};