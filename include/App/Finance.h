#include <Arduino.h>
#include <App.h>

class Finance : public App
{

public:
    Finance();
    Finance(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService);
    void draw();
    void draw_widget(){};
    void background(){};

private:
    bool first_time;
    int y_position;

    String coin_id[3] = {""};
    String coin_name[3] = {""};
    long coin_price[3] = {0};
    float coin_price_change[3] = {0};
};
