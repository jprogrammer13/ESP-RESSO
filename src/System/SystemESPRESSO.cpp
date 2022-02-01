#include <Arduino.h>
#include <System/SystemESPRESSO.h>

void SystemESPRESSO::serviceRegistration()
{
    services.insert(std::pair<String, Service *>("ServiceTempHumidity", new ServiceTempHumidity()));
    services.insert(std::pair<String, Service *>("ServiceTempLog", new ServiceTempLog()));
    services.insert(std::pair<String, Service *>("ServiceRelay", new ServiceRelay()));
    services.insert(std::pair<String, Service *>("ServiceWeather", new ServiceWeather(this->wifi)));
    services.insert(std::pair<String, Service *>("ServiceTime", new ServiceTime(this->wifi)));
    services.insert(std::pair<String, Service *>("ServiceWiFi", new ServiceWiFi(this->wifi)));
    services.insert(std::pair<String, Service *>("ServiceMQTT", new ServiceMQTT(this->wifi, this->mqtt)));
    services.insert(std::pair<String, Service *>("ServiceTempHumidityMQTT", new ServiceTempHumidityMQTT(this->wifi, this->mqtt)));
    services.insert(std::pair<String, Service *>("ServiceControlMQTT", new ServiceControlMQTT(this->wifi, this->mqtt)));
}

void SystemESPRESSO::applicationRegistration()
{
    applications.insert(std::pair<String, App *>("Config", new Config(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("Menu", new Menu(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("Home", new Home(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("Stats", new Stats(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("Weather", new Weather(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("HomeControl", new HomeControl(navigation, display, systemUi, systemServices)));
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

    mqtt = new Adafruit_MQTT_Client(&(wifiClientSecure), "io.adafruit.com", 8883, "Riccardo136", "c6056b140d174bdfbe55d6fb637e8695");
    wifiClientSecure.setCACert(adafruitio_root_ca);

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
    systemUi->setUi("Config");
}

void SystemESPRESSO::runBackground()
{
    if (this->wifi->status() == WL_CONNECTED) // EXECUTE ONLY IF WIFI IS AVAIABLE
    {
        for (auto const &f : backgroundProcess)
        {
            applications[f]->background();
        }
    }
}

void SystemESPRESSO::run()
{
    navigation->update();
    this->runBackground();
    systemUi->pageRender();
}