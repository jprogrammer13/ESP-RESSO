#ifndef __NAVIGATION_H__
#define __NAVIGATION_H__
#include <Arduino.h>
#include <actions.h>
#include <ESP32Encoder.h>
#include <Button.h>
#include <config.h>

class Navigation
{
public:
    Navigation(){};
    Navigation(uint8_t _B_BACK, uint8_t _B_SLC, uint8_t _CLK, uint8_t _DT);
    void begin();
    void update();
    Action get_action();

private:
    ESP32Encoder encoder;
    Action action;
    Button B_BACK;
    Button B_SLC;
    int states[3];
};

#endif