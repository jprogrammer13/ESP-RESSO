#include <Arduino.h>
#include <App.h>

class Config : public App
{

public:
    Config();
    Config(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService);
    void draw();
    void draw_widget(){};
    void background(){};

private:
    unsigned long t_start;
};
