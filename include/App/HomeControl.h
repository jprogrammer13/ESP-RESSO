#include <Arduino.h>
#include <App.h>

class HomeControl : public App
{

public:
    HomeControl();
    HomeControl(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService);
    void draw();
    void draw_widget(){};
    void background(){};

private:
    int control_position;
    unsigned long t_send_message;
    bool send_message;
    bool disable_sending;
};
