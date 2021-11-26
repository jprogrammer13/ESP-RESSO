#ifndef __SYSTEM_SERVICES_H__
#define __SYSTEM_SERVICES_H__
#include <Arduino.h>
#include <Service.h>
#include <map>

class SystemServices
{
public:
    SystemServices();
    void registerServices(std::map<String, Service *> *_services);
    String sendMsg(String serviceName, String msg);

private:
    std::map<String, Service *> *services;
};

#endif