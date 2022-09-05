#include <Arduino.h>
#include <App.h>

class Frame : public App
{

public:
    Frame();
    Frame(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService);
    void draw();
    void draw_widget(){};
    void background(){};
    void get_time_service();

private:
    unsigned long t_start;
    bool photo_select;
    int hour;
    int minute;
    bool first_time;
};
