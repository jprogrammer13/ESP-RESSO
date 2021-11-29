#ifndef __SERVICE_H__
#define __SERVICE_H__
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

class Service
{
public:
    WiFiClass *wifi;
    Service(){};
    Service(WiFiClass *_wifi)
    {
        this->wifi = _wifi;
    };

    // JSON standard for service comunication
    /**
     * Send structre
     * @action: (send,get)
     * @data: (any type es Array, Number, String, JSON)
     */

    /**
     * Recive structre
     * @data: (any type es Array, Number, String, JSON)
     */
    virtual String sendMsg(String msg);
};

#endif