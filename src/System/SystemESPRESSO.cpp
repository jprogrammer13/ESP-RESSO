#include <Arduino.h>
#include <System/SystemESPRESSO.h>

void SystemESPRESSO::serviceRegistration()
{
    services.insert(std::pair<String, Service *>("ServiceTempHumidity", new ServiceTempHumidity()));
    services.insert(std::pair<String, Service *>("ServiceRelay", new ServiceRelay()));
    services.insert(std::pair<String, Service *>("ServiceWeather", new ServiceWeather(this->wifi)));
    services.insert(std::pair<String, Service *>("ServiceTime", new ServiceTime(this->wifi)));
    services.insert(std::pair<String, Service *>("ServiceWiFi", new ServiceWiFi(this->wifi)));
    services.insert(std::pair<String, Service *>("ServiceMQTT", new ServiceMQTT(this->wifi, this->mqtt)));
    services.insert(std::pair<String, Service *>("ServiceTempHumidityMQTT", new ServiceTempHumidityMQTT(this->wifi, this->mqtt)));
    services.insert(std::pair<String, Service *>("ServiceControlMQTT", new ServiceControlMQTT(this->wifi, this->mqtt)));
    services.insert(std::pair<String, Service *>("ServiceFinance", new ServiceFinance(this->wifi)));
}

void SystemESPRESSO::applicationRegistration()
{
    applications.insert(std::pair<String, App *>("Config", new Config(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("Menu", new Menu(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("Home", new Home(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("Frame", new Frame(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("Weather", new Weather(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("HomeControl", new HomeControl(navigation, display, systemUi, systemServices)));
    applications.insert(std::pair<String, App *>("Finance", new Finance(navigation, display, systemUi, systemServices)));
}

void SystemESPRESSO::backgroundFunctionRegistration()
{
    backgroundProcess.push_back("Home");
}

SystemESPRESSO::SystemESPRESSO()
{

    navigation = new Navigation(B_BACK_PIN, B_SLC_PIN, ENCODER_CLK_PIN, ENCODER_DT_PIN);

    systemUi = new SystemUi();
    systemServices = new SystemServices();

    display = new Display(U8G2_R0, DISPLAY_CLOCK_PIN, DISPLAY_DATA_PIN, DISPLAY_CS_PIN);

    wifi = new WiFiClass();

    mqtt = new Adafruit_MQTT_Client(&(wifiClientSecure), ADAFRUIT_SERVER, ADAFRUIT_SERVER_PORT, ADAFRUIT_USERNAME, ADAFRUIT_API_KEY);
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