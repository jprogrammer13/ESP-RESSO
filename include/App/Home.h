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

private:
    int t_start;
    int t_tmp_start;
    float temp_current; // temp corrente
    int humidity;
    float temp_selected; // temp desiderata
    float tmp_temp;

    int hour;
    int minute;
    String day_week;
    int day;
};
