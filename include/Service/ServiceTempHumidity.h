#include <Arduino.h>
#include <Service.h>
#include <DHT.h>

class ServiceTempHumidity : public Service
{
public:
    ServiceTempHumidity();
    String sendMsg(String msg);

private:
    DHT tempSensor = DHT(27, DHT11);
    float temperature;
    float humidity;
    unsigned long t_start;
};