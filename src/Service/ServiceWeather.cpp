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
            return "error";
        }

        long list_item_sunrise[data_n_day];
        long list_item_sunset[data_n_day];
        float list_item_temp_day[data_n_day];
        float list_item_temp_min[data_n_day];
        float list_item_temp_max[data_n_day];
        float list_item_temp_night[data_n_day];
        float list_item_temp_eve[data_n_day];
        float list_item_temp_morn[data_n_day];

        for (JsonObject list_item : response["list"].as<JsonArray>())
        {
            for (int nth_day; nth_day < data_n_day; nth_day++)
            {
                list_item_sunrise[nth_day] = list_item["sunrise"]; // 1638167700, 1638254172, 1638340644
                list_item_sunset[nth_day] = list_item["sunset"];   // 1638199986, 1638286356, 1638372729

                JsonObject list_item_temp = list_item["temp"];
                list_item_temp_day[nth_day] = list_item_temp["day"];     // 6.75, 6.01, 8.54
                list_item_temp_min[nth_day] = list_item_temp["min"];     // -1.44, -0.38, 2.26
                list_item_temp_max[nth_day] = list_item_temp["max"];     // 6.84, 6.87, 8.54
                list_item_temp_night[nth_day] = list_item_temp["night"]; // 0.77, 2.54, 3.12
                list_item_temp_eve[nth_day] = list_item_temp["eve"];     // 4.34, 2.45, 3.05
                list_item_temp_morn[nth_day] = list_item_temp["morn"];   // 2.28, -0.27, 2.34

                int list_item_humidity = list_item["humidity"]; // 48, 34, 56

                JsonObject list_item_weather_0 = list_item["weather"][0];
                const char *list_item_weather_0_main = list_item_weather_0["main"]; // "Clouds", "Clear", "Clear"
            }
        }
        
    }
    else
    {
    }
    // Free resources
    http.end();


}