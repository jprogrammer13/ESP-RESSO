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
    void set_relay(bool state);

private:
    unsigned long t_start;
    unsigned long t_tmp_start;
    unsigned long t_time;
    unsigned long t_weather;
    unsigned long t_temp_check;

    float temp_current; // temp corrente
    int humidity;
    float temp_selected; // temp desiderata
    float tmp_temp;

    int hour;
    int minute;
    String day_week;
    int day;

    bool first_time;
};
