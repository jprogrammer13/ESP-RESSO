#include <Arduino.h>
#include <gfx_extended.h>

Display::Display(const u8g2_cb_t *rotation, uint8_t clock, uint8_t data, uint8_t cs, uint8_t reset) : U8G2_ST7920_128X64_F_SW_SPI(rotation, clock, data, cs, reset)
{
}

void Display::drawThickLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t radius, bool highQuality)
{
    // see p3dt_gfx_2d_license.txt

    // see p3dt_gfx_2d_license.txt
    int32_t tmp;
    int32_t x, y;
    int32_t dx, dy;
    int32_t err;
    int32_t ystep;

    uint8_t swapxy = 0;

    /* no intersection check at the moment, should be added... */

    if (x1 > x2)
        dx = x1 - x2;
    else
        dx = x2 - x1;
    if (y1 > y2)
        dy = y1 - y2;
    else
        dy = y2 - y1;

    if (dy > dx)
    {
        swapxy = 1;
        tmp = dx;
        dx = dy;
        dy = tmp;
        tmp = x1;
        x1 = y1;
        y1 = tmp;
        tmp = x2;
        x2 = y2;
        y2 = tmp;
    }
    if (x1 > x2)
    {
        tmp = x1;
        x1 = x2;
        x2 = tmp;
        tmp = y1;
        y1 = y2;
        y2 = tmp;
    }
    err = dx >> 1;
    if (y2 > y1)
        ystep = 1;
    else
        ystep = -1;
    y = y1;

    if (x2 == 0xffff)
        x2--;

    for (x = x1; x <= x2; x++)
    {
        if (swapxy == 0)
        {
            if (highQuality)
            {
                this->drawDisc(x, y, radius);
            }
            else
            {
                this->drawCircle(x, y, radius);

                if (radius > 2)
                {
                    this->drawCircle(x, y, radius - 1);
                }
                if (radius > 3)
                {
                    this->drawCircle(x, y, radius - 2);
                }
            }
        }
        else
        {
            if (highQuality)
            {
                this->drawDisc(x, y, radius);
            }
            else
            {
                this->drawCircle(x, y, radius);

                if (radius > 2)
                {
                    this->drawCircle(x, y, radius - 1);
                }
                if (radius > 3)
                {
                    this->drawCircle(x, y, radius - 2);
                }
            }
        }

        err -= (uint8_t)dy;
        if (err < 0)
        {
            y += (uint16_t)ystep;
            err += (uint16_t)dx;
        }
    }
}

void Display::drawArc(int32_t cx, int32_t cy, float start, float stop, uint16_t radius, uint8_t lineRadius, uint16_t steps, bool highQuality)
{
    int32_t x1 = rpx(cx, radius, start);
    int32_t y1 = rpy(cy, radius, start);
    // printf("\ndraw from %f,%f in %d steps", start, stop, steps);

    float arcLength = stop - start;

    for (uint16_t i = 1; i <= steps; i++)
    {
        float segmentLength = i * (arcLength / steps);
        // printf("\n rpx(%d, %d, %f +  %f)", cx, radius, start, segmentLength);

        int32_t x2 = rpx(cx, radius, start + segmentLength);
        int32_t y2 = rpy(cy, radius, start + segmentLength);
        // printf("\n gfx2d.drawLine(%d, %d, %d, %d, color);", x1, y1, x2, y2);
        drawThickLine(x1, y1, x2, y2, lineRadius, highQuality);
        // this->drawLine(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
    }
}

void Display::drawDithering(int sx, int sy, int w, int h, int percent, int size)
{
    switch (percent)
    {
    // 75% (DARK GREY)
    case (75):

        for (int y = sy; y < sy + h; y++)
        {
            for (int x = sx; x < sx + w; x++)
            {
                if (y % 2 == 0)
                {
                    if (x % 2 != 0)
                    {
                        drawBox(x, y, size, size);
                    }
                }
                else
                {
                    drawBox(x, y, size, size);
                }
            }
        }
        break;

    // 50% (MIDDLE GREY)
    case (50):

        for (int y = sy; y < sy + h; y++)
        {
            for (int x = sx; x < sx + w; x++)
            {
                if (y % 2 == 0)
                {
                    if (x % 2 != 0)
                    {
                        drawBox(x, y, size, size);
                    }
                }
                else if (x % 2 == 0)
                {
                    drawBox(x, y, size, size);
                }
            }
        }
        break;

        // 25% (LIGHT GREY)
    case (25):

        for (int y = sy; y < sy + h; y++)
        {
            for (int x = sx; x < sx + w; x++)
            {
                if (y % 2 != 0)
                {
                    if (x % 2 == 0)
                    {
                        drawBox(x, y, size, size);
                    }
                }
            }
        }
        break;
    }
}
