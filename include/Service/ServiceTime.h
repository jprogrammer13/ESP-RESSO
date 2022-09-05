#include <Arduino.h>
#include <Service.h>
#include "time.h"

class ServiceTime : public Service
{
public:
    ServiceTime();
    ServiceTime(WiFiClass *_wifi);
    String sendMsg(String msg);

private:
    String ntp_server;
    unsigned long t_start;
};