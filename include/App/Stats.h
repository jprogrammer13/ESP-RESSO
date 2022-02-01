#include <Arduino.h>
#include <App.h>

class Stats : public App
{

public:
    Stats();
    Stats(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService);
    void draw();
    void draw_widget(){};
    void background(){};

private:
};
