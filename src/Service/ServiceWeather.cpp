#include <Arduino.h>
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

    //GET THE DATA
    String tmp = "https://api.openweathermap.org/data/2.5/forecast/daily?q=" + String(data_city) + "&cnt=" + String(data_n_day) + "&units=metric&appid=" + API_key;
    http.begin(tmp.c_str());

    // Send HTTP GET request
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0)
    {
        String payload = http.getString();

        // String input;

        StaticJsonDocument<2048> response;

        DeserializationError error = deserializeJson(response, payload);

        if (error)
        {
            Serial.print("deserializeJson() failed: ");
            Serial.println(error.c_str());
            return;
        }

        long list_item_sunrise;
        long list_item_sunset;
        float list_item_temp_day;
        float list_item_temp_min;
        float list_item_temp_max;
        float list_item_temp_night;

        for (JsonObject list_item : response["list"].as<JsonArray>())
        {
            list_item_sunrise = list_item["sunrise"]; // 1638167700, 1638254172, 1638340644
            list_item_sunset = list_item["sunset"];   // 1638199986, 1638286356, 1638372729

            JsonObject list_item_temp = list_item["temp"];
            list_item_temp_day = list_item_temp["day"];     // 6.75, 6.01, 8.54
            list_item_temp_min = list_item_temp["min"];     // -1.44, -0.38, 2.26
            list_item_temp_max = list_item_temp["max"];     // 6.84, 6.87, 8.54
            list_item_temp_night = list_item_temp["night"]; // 0.77, 2.54, 3.12
            float list_item_temp_eve = list_item_temp["eve"];     // 4.34, 2.45, 3.05
            float list_item_temp_morn = list_item_temp["morn"];   // 2.28, -0.27, 2.34

            int list_item_humidity = list_item["humidity"]; // 48, 34, 56

            JsonObject list_item_weather_0 = list_item["weather"][0];
            const char *list_item_weather_0_main = list_item_weather_0["main"];               // "Clouds", "Clear", "Clear"
 
        }
    }
    else
    {
    }
    // Free resources
    http.end();
}