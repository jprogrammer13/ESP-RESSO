#include <Arduino.h>
#define ARDUINOJSON_USE_LONG 1
#include <Service/ServiceFinance.h>

ServiceFinance::ServiceFinance(){};

ServiceFinance::ServiceFinance(WiFiClass *_wifi) : Service(_wifi)
{
    API_key = FINANCE_API_KEY;
}

String ServiceFinance::sendMsg(String msg)
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

    if (strcmp(action, "get") == 0)
    {

        //GET THE DATA
        String tmp = "https://api.coinranking.com/v2/coins?limit=3";
        http.addHeader("x-access-token", API_key); //Specify content-type header
        http.begin(tmp.c_str());

        // Send HTTP GET request
        int httpResponseCode = http.GET();

        if (httpResponseCode > 0)
        {
            String payload = http.getString();
            // Serial.println(payload);

            DynamicJsonDocument response(512);
            DynamicJsonDocument api_response(6144);

            DeserializationError error = deserializeJson(api_response, payload);

            if (error)
            {
                Serial.print("deserializeJson() failed: ");
                Serial.println(error.c_str());
                return "error";
            }

            JsonObject data_response = response.createNestedObject("data");
            JsonArray data_response_coin_id = data_response.createNestedArray("coin_id");
            JsonArray data_response_coin_name = data_response.createNestedArray("coin_name");
            JsonArray data_response_price = data_response.createNestedArray("price");
            JsonArray data_response_change = data_response.createNestedArray("change");

            for (JsonObject data_coin : api_response["data"]["coins"].as<JsonArray>())
            {
                data_response_coin_id.add(data_coin["symbol"]);
                data_response_coin_name.add(data_coin["name"]);
                data_response_price.add(data_coin["price"]);
                data_response_change.add(data_coin["change"]);
            }

            serializeJson(response, responseMsg);
        }
        else
        {
            responseMsg = "err";
        }

        // Free resources
        http.end();
    }

    return responseMsg;
}