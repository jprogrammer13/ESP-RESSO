#include <Arduino.h>
#include <Service.h>
#include <DHT.h>

class ServiceRelay : public Service
{
public:
    ServiceRelay();
    String sendMsg(String msg);

private:
    bool status;
    uint8_t relay_pin;
};