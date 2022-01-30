#include <Arduino.h>
#include <App.h>
#include <map>

class Menu : public App
{

public:
    Menu();
    Menu(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService);
    void draw();
    void draw_widget(){};
    void background(){};

private:
    int position;
    int n_applications;
    std::map<String, int> applications;
};