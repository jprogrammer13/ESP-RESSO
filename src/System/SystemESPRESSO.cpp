#include <Arduino.h>
#include <System/SystemESPRESSO.h>

void SystemESPRESSO::serviceRegistration()
{
    services.insert(std::pair<String, Service *>("ServiceTempHumidity", new ServiceTempHumidity()));
    services.insert(std::pair<String, Service *>("ServiceRelay", new ServiceRelay()));
    services.insert(std::pair<String, Service *>("ServiceWeather", new ServiceWeather(this->wifi)));
    services.insert(std::pair<String, Service *>("ServiceTime", new ServiceTime(this->wifi)));
    services.insert(std::pair<String, Service *>("ServiceWiFi", new ServiceWiFi(this->wifi)));
}

void SystemESPRESSO::applicationRegistration()
{
    applications.insert(std::pair<String, App *>("Home", new Home(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("Test", new Test(navigation, display, systemUi, systemServices)));
}

void SystemESPRESSO::backgroundFunctionRegistration()
{
    backgroundProcess.push_back("Home");
}

SystemESPRESSO::SystemESPRESSO()
{
    navigation = new Navigation(4, 12, 21, 22);

    systemUi = new SystemUi();
    systemServices = new SystemServices();

    display = new Display(U8G2_R0, 18, 23, 5);

    wifi = new WiFiClass();

    // Network information
    this->ssid = "TIM-19861131";
    this->ssid_pswd = "BussolaGay";

    // INITIALIZE APPLICATIONS AND BACKGROUN FUNCTIONS

    this->serviceRegistration();
    this->applicationRegistration();
    this->backgroundFunctionRegistration();
}

void SystemESPRESSO::begin()
{
    navigation->begin();
    display->begin();

    systemServices->registerServices(&services);
    systemUi->registerApplications(&applications);
    systemUi->setUi("Home");
}

void SystemESPRESSO::runBackground()
{
    for (auto const &f : backgroundProcess)
    {
        // Serial.println(f);
        applications[f]->background();
    }
}

void SystemESPRESSO::run()
{
    navigation->update();
    this->runBackground();
    systemUi->pageRender();
}