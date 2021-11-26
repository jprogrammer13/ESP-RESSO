#include <Arduino.h>
#include <App.h>

class Test : public App
{

public:
    Test();
    Test(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService);
    void draw();
    void draw_widget(){};
    void background(){};

private:
    int numero;
};
