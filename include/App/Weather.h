#include <Arduino.h>
#include <App.h>

class Weather : public App
{

public:
    Weather();
    Weather(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService);
    void draw();
    void draw_widget(){};
    void background(){};

private:
    bool first_time;
    String msg;
    String response;
    // CREI VARIABILI PER TUTTI I DATI CHE TI INTERESSANO
    String city;
    int no_day;
    float data_temp_min;
    float data_temp_max;
    int data_humidity;
    const char *data_weather_main;
    const char *data_weather_description;

    int y_position;

    int weather_icon;

    String weather_descriptions[6] = {"Thunderstorm", "Drizzle", "Rain",
                                      "Snow", "Clear", "Clouds"};
    int weather_icons[6] = {0x0060, 0x0055, 0x00f1,
                            0x00b1, 0x0103, 0x007c};
};
