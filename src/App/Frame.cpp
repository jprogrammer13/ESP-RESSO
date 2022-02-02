#include <Arduino.h>
#include <App.h>
#include <App/Frame.h>

Frame::Frame(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    t_start = millis();
    photo_select = true;
    hour = 0;
    minute = 0;
    first_time = true;
}

void Frame::draw()
{

    // UPDATE TIME EVERY 30s
    if (millis() - t_start > 30000 || first_time)
    {
        first_time = 0;
        t_start = millis();
        this->get_time_service();
    }

    display->firstPage();
    do
    {
        display->setDrawColor(0);
        display->drawXBM(0, 0, 128, 64, (photo_select) ? skyline : moon);
        display->setDrawColor((photo_select) ? 0 : 1);
        display->drawRBox(2, 43, 33, 19, 4);
        display->setDrawColor((photo_select) ? 1 : 0);
        display->setFont(u8g2_font_6x13_tn);
        String tmp_time = ((hour < 10) ? ("0" + String(hour)) : String(hour)) + ":" + ((minute < 10) ? ("0" + String(minute)) : String(minute));
        display->drawStr(4, 57, tmp_time.c_str());
        display->setDrawColor(1);

    } while (display->nextPage());

    switch (navigation->get_action())
    {
    case A_BACK:
        sysUi->setUi("Menu");
        break;
    case A_SELECT:
        photo_select = !photo_select;
        break;
    }
}

void Frame::get_time_service()
{
    String msg = "{\"action\":\"get\",\"data\":{\"gmt_offset\":3600,\"light_offest\":3600}}";
    String response = sysServices->sendMsg("ServiceTime", msg);

    DynamicJsonDocument doc(256);

    DeserializationError error = deserializeJson(doc, response);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
    }

    JsonObject data = doc["data"];
    this->hour = data["hour"];
    this->minute = data["minute"];
}