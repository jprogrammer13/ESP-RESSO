#include <Arduino.h>
#include <Service/ServiceWiFi.h>

ServiceWiFi::ServiceWiFi(){};

ServiceWiFi::ServiceWiFi(WiFiClass *_wifi) : Service(_wifi)
{
    t_start = millis();
}

String ServiceWiFi::sendMsg(String msg)
{
    String responseMsg;
    // expected "action":"send"
    DynamicJsonDocument doc(255);

    DeserializationError error = deserializeJson(doc, msg);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return "error";
    }

    const char *action = doc["action"]; // "send"

    const char *data_wifi_mode = doc["data"]["wifi_mode"]; // "WIFI_STA
    const char *data_ssid = doc["data"]["ssid"];
    const char *data_psw = doc["data"]["psw"];

    DynamicJsonDocument response(16);

    if (strcmp(action, "send") == 0)
    {
        if (strcmp(data_wifi_mode, "WIFI_STA") == 0)
        {
            wifi->mode(WIFI_STA);
            wifi->begin(data_ssid, data_psw);
            Serial.println("Connecting");
            unsigned long t_start = millis();
            while (wifi->status() != WL_CONNECTED && millis() - t_start < 30000)
            {
                delay(500);
            }
            if (wifi->status() == WL_CONNECTED)
            {
                response["data"] = 1;
            }
            else
            {
                response["data"] = 0;
            }
        }
        else if (strcmp(data_wifi_mode, "WIFI_AP") == 0)
        {
            wifi->mode(WIFI_AP);
            wifi->softAP(data_ssid, data_psw);
            response["data"] = 1;
        }
        serializeJson(response, responseMsg);
    }
    else
    {
        return "error";
    }

    return responseMsg;
}