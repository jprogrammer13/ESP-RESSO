#ifndef __SERVICE_H__
#define __SERVICE_H__
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <config.h>

class Service
{
public:
    WiFiClass *wifi;
    Adafruit_MQTT_Client *mqtt;
    Service(){};
    Service(WiFiClass *_wifi)
    {
        this->wifi = _wifi;
    };
    Service(WiFiClass *_wifi, Adafruit_MQTT_Client *_mqtt)
    {
        this->wifi = _wifi;
        this->mqtt = _mqtt;
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