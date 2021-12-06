#include <Arduino.h>
#include <System/SystemESPRESSO.h>

void SystemESPRESSO::serviceRegistration()
{
    services.insert(std::pair<String, Service *>("ServiceTempHumidity", new ServiceTempHumidity()));
    services.insert(std::pair<String, Service *>("ServiceRelay", new ServiceRelay()));
    services.insert(std::pair<String, Service *>("ServiceWeather", new ServiceWeather(this->wifi)));
    services.insert(std::pair<String, Service *>("ServiceTime", new ServiceTime(this->wifi)));
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

    // Network information
    this->ssid = "Riky Hotspot";
    this->ssid_pswd = "Riccardo_13";

    // INITIALIZE APPLICATIONS AND BACKGROUN FUNCTIONS

    this->serviceRegistration();
    this->applicationRegistration();
    this->backgroundFunctionRegistration();
}

void SystemESPRESSO::begin()
{
    navigation->begin();
    display->begin();

    wifi = new WiFiClass();
    wifi->mode(WIFI_STA);
    Serial.println(this->ssid.c_str());
    Serial.println(this->ssid_pswd.c_str());
    wifi->begin(this->ssid.c_str(), this->ssid_pswd.c_str());
    Serial.println("Connecting");
    while (wifi->status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(wifi->status());
    }
    Serial.println("Connected");

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