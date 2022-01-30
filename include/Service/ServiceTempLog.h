#include <Arduino.h>
#include <Service.h>
#include <map>

class ServiceTempLog : public Service
{
public:
    ServiceTempLog();
    String sendMsg(String msg);

private:

    unsigned long t_start;
    std::map<int, unsigned long> temp_logs;
};