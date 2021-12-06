#include <Arduino.h>
#define ARDUINOJSON_USE_DOUBLE 1
#include <Service/ServiceWeather.h>

ServiceWeather::ServiceWeather(){};

ServiceWeather::ServiceWeather(WiFiClass *_wifi) : Service(_wifi)
{
    API_key = "6f3d3af7da198e596a118561c69807db";
    t_start = millis();
}

String ServiceWeather::sendMsg(String msg)
{
    String responseMsg;
    // expected "action":"get"
    // data can be:
    /**
     * @city: name of the city
     * @n_day: number of future day
     */

    StaticJsonDocument<128> doc;

    DeserializationError error = deserializeJson(doc, msg);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return "error";
    }

    const char *action = doc["action"];

    const char *data_city = doc["data"]["city"];
    int data_n_day = doc["data"]["n_day"];

    if (strcmp(action, "get") == 0)
    {
        data_n_day = (data_n_day > 2) ? 2 : data_n_day;
        //GET THE DATA
        String tmp = "https://api.openweathermap.org/data/2.5/forecast/daily?q=" + String(data_city) + "&cnt=" + String(data_n_day) + "&units=metric&appid=" + API_key;
        http.begin(tmp.c_str());

        // Send HTTP GET request
        int httpResponseCode = http.GET();

        if (httpResponseCode > 0)
        {
            String payload = http.getString();

            DynamicJsonDocument response(512);
            StaticJsonDocument<2048> api_response;

            DeserializationError error = deserializeJson(api_response, payload);

            if (error)
            {
                Serial.print("deserializeJson() failed: ");
                Serial.println(error.c_str());
                return "error";
            }

            JsonObject data_r = response.createNestedObject("data");
            JsonArray data_temp_morning = data_r.createNestedArray("temp_morning");
            JsonArray data_temp_day = data_r.createNestedArray("temp_day");
            JsonArray data_temp_evening = data_r.createNestedArray("temp_evening");
            JsonArray data_temp_night = data_r.createNestedArray("temp_night");
            JsonArray data_temp_min = data_r.createNestedArray("temp_min");
            JsonArray data_temp_max = data_r.createNestedArray("temp_max");
            JsonArray data_humidity = data_r.createNestedArray("humidity");
            JsonArray data_weather = data_r.createNestedArray("weather");

            for (JsonObject list_item : api_response["list"].as<JsonArray>())
            {

                JsonObject list_item_temp = list_item["temp"];
                data_temp_morning.add(list_item_temp["morn"]);
                data_temp_day.add(list_item_temp["day"]);
                data_temp_evening.add(list_item_temp["eve"]);
                data_temp_night.add(list_item_temp["night"]);
                data_temp_min.add(list_item_temp["min"]);
                data_temp_max.add(list_item_temp["max"]);
                data_humidity.add(list_item["humidity"]);

                JsonObject list_item_weather_0 = list_item["weather"][0];
                data_weather.add(list_item_weather_0["main"].as<String>());
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