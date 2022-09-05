#include <Arduino.h>
#include <App.h>

class Home : public App
{

public:
    Home();
    Home(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService);
    void draw();
    void draw_widget(){};
    void background();
    void get_temp_sensor();
    void get_time_service();
    void get_weather_service();
    void set_relay(bool state);

private:
    unsigned long t_tmp_start;
    unsigned long t_sensor;      // for sensor reading
    unsigned long t_time;        // for time update
    unsigned long t_weather;     // for weather update
    unsigned long t_mqtt_pub;    // for mqtt update
    unsigned long t_relay_check; // for goal temperature chech
    unsigned long t_temp_check;  // for temperature stats
    int weather_icon;

    float temp_current; // temp corrente
    int humidity;
    float temp_selected; // temp desiderata
    float temp_selected_online;
    float temp_cur_check; // check if temp_current is changed
    float tmp_temp;

    int hour;
    int minute;
    String day_week;
    int day;

    bool first_time;
    bool thermostat_on;

    String weather_descriptions[6] = {"Thunderstorm", "Drizzle", "Rain",
                                       "Snow", "Clear", "Clouds"};
    int weather_icons[6] = {0x0060, 0x0055, 0x00f1,
                             0x00b1, 0x0103, 0x007c};
};
