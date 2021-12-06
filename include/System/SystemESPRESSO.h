#ifndef __SYSTEM_ESPRESSO_H__
#define __SYSTEM_ESPRESSO_H__

#include <Arduino.h>
#include <map>
#include <list>

#include <System/SystemUi.h>
#include <System/SystemServices.h>
#include <gfx_extended.h>

#include <Navigation.h>

#include <Service/services.h>
#include <App/applications.h>

#include <WiFi.h>

class SystemESPRESSO
{
public:
    SystemESPRESSO();
    void serviceRegistration();
    void applicationRegistration();
    void backgroundFunctionRegistration();
    void begin();
    void runBackground();
    void run();

private:
    //System Utility
    SystemUi *systemUi;
    SystemServices *systemServices;

    Navigation *navigation;

    // DISPLAY
    Display *display;

    std::map<String, Ui *> applications;
    std::list<String> backgroundProcess;
    std::map<String, Service *> services;

    // Network

    WiFiClass *wifi;
    String ssid;
    String ssid_pswd;
};

#endif