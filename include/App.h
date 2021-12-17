#ifndef __APP_H__
#define __APP_H__
#include <Arduino.h>
#include <U8g2lib.h>
#include <gfx_extended.h>
#include <Navigation.h>
#include <System/SystemUi.h>
#include <System/SystemServices.h>

class App : public Ui
{
public:
    App(){};
    App(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService)
    {
        this->navigation = _navigation;
        this->display = _display;
        this->sysUi = _sysUi;
        this->sysServices = _sysService;
    }
    // You must override
    virtual void draw() = 0;
    // Optional
    virtual void draw_widget();
    virtual void background();

    //
    Navigation *navigation;
    Display *display;
    SystemUi *sysUi;
    SystemServices *sysServices;
};

#endif