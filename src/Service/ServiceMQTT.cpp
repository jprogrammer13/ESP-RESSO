#include <Arduino.h>
#include <Service/ServiceMQTT.h>

ServiceMQTT::ServiceMQTT(){};

ServiceMQTT::ServiceMQTT(WiFiClass *_wifi, Adafruit_MQTT_Client *_mqtt) : Service(_wifi, _mqtt)
{
    t_start = millis();
}

String ServiceMQTT::sendMsg(String msg)
{
    String responseMsg;

    // expected "action":"send"
    DynamicJsonDocument doc(255);

    DeserializationError error = deserializeJson(doc, msg);
    // Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return "error";
    }

    const char *action = doc["action"]; // "send"

    const char *data_action = doc["data"]["action"];

    DynamicJsonDocument response(16);

    if (strcmp(action, "send") == 0)
    {

        if (strcmp(data_action, "connect") == 0)
        {
            int8_t ret;

            // Stop if already connected.
            if (this->mqtt->connected())
            {
                // Serial.println("MQTT IS CONNECTED");
                return "{\"data\":1}";
            }

            // Serial.print("Connecting to MQTT... ");

            uint8_t retries = 5;
            while ((ret = this->mqtt->connect()) != 0)
            { // connect will return 0 for connected
                Serial.println(this->mqtt->connectErrorString(ret));
                // Serial.println("Retrying MQTT connection in 5 seconds...");
                this->mqtt->disconnect();
                delay(5000); // wait 5 seconds
                retries--;
                if (retries == 0)
                {
                    // basically die and wait for WDT to reset me
                    return "{\"data\":0}";
                }
            }
            // Serial.println("MQTT Connected!");
            return "{\"data\":1}";
        }
    }
    else
    {
        return "error";
    }

    return responseMsg;
}