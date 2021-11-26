#include <Arduino.h>
#include <System/SystemServices.h>

SystemServices::SystemServices(){};

void SystemServices::registerServices(std::map<String, Service *> *_services)
{
    this->services = _services;
}

String SystemServices::sendMsg(String serviceName, String msg)
{
    return (*services)[serviceName]->sendMsg(msg);
}