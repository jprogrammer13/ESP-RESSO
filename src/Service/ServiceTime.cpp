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

    StaticJsonDocument<255> response;

    JsonObject data_r = response.createNestedObject("data");

    if (strcmp(action, "get") == 0)
    {
        configTime(data_gmt_offset, data_light_offest, ntp_server.c_str());
        struct tm timeinfo;
        if (getLocalTime(&timeinfo))
        {
            Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");

            char s_day_name[255];
            char s_month[255];
            char s_day[255];
            char s_year[255];
            char s_hour[255];
            char s_minute[255];
            char s_second[255];

            strftime(s_day_name, 255, "%A", &timeinfo);
            strftime(s_month, 255, "%B", &timeinfo);
            strftime(s_day, 255, "%d", &timeinfo);
            strftime(s_year, 255, "%Y", &timeinfo);
            strftime(s_hour, 255, "%H", &timeinfo);
            strftime(s_minute, 255, "%M", &timeinfo);
            strftime(s_second, 255, "%S", &timeinfo);

            data_r["day_name"] = String(s_day_name);
            data_r["month"] = String(s_month);
            data_r["day"] = String(s_day).toInt();
            data_r["year"] = String(s_year).toInt();
            data_r["hour"] = String(s_hour).toInt();
            data_r["minute"] = String(s_minute).toInt();
            data_r["second"] = String(s_second).toInt();

            serializeJson(response, responseMsg);
        }
        else
        {
            return "error";
        }
    }

    return responseMsg;
};