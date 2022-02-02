#ifndef __U8G2_EXT_H__
#define __U8G2_EXT_H__

#include <Arduino.h>
#include <U8g2lib.h>
#include <utils.h>
#include <config.h>

class Display : public U8G2_ST7920_128X64_F_SW_SPI
{
public:
    Display(const u8g2_cb_t *rotation, uint8_t clock, uint8_t data, uint8_t cs, uint8_t reset = U8X8_PIN_NONE);
    // EXTENDED FUNCTIONS
    void drawThickLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t radius, bool highQuality = false);
    void drawArc(int32_t cx, int32_t cy, float start, float stop, uint16_t radius, uint8_t lineRadius, uint16_t steps = 100, bool highQuality = false);
    void drawDithering(int sx, int sy, int w, int h, int percent, int size);
};

#endif