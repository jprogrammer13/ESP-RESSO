#include <Arduino.h>
#include <Service.h>
#include <DHT.h>

class ServiceTempHumidity : public Service
{
public:
    ServiceTempHumidity();
    String sendMsg(String msg);

private:
    DHT tempSensor = DHT(DHT11_PIN, DHT11);
    float temperature;
    float humidity;
    unsigned long t_start;
};