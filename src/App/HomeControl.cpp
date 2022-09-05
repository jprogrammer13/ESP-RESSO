#include <Arduino.h>
#include <App.h>
#include <App/HomeControl.h>

HomeControl::HomeControl(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    control_position = 0;
    send_message = false;
    disable_sending = false;
}

void HomeControl::draw()
{
    display->firstPage();
    do
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                display->setDrawColor(1);
                (((3 * i) + j) == control_position) ? display->drawRBox(5 + (47 * j), 5 + (29 * i), 25, 25, 3) : display->drawRFrame(5 + (47 * j), 5 + (29 * i), 25, 25, 3);
                display->setDrawColor((((3 * i) + j) == control_position) ? 0 : 1);
                display->setFont(u8g2_font_9x15_tn);
                display->drawStr(13 + (47 * j), 23 + (29 * i), String((3 * i) + j).c_str());
                display->setDrawColor(1);
            }
        }
        if (send_message)
        {
            if (millis() - t_send_message > 1000)
            {
                send_message = false;
                disable_sending = false;
            }
            display->setDrawColor(1);
            display->drawBox(0, 0, 128, 64);
            int x = display->getStrWidth((String("command") + String(control_position)).c_str());
            display->setFont(u8g2_font_7x14_tf);
            display->setDrawColor(0);
            display->setCursor(30, 39);
            display->print(("command" + String(control_position)).c_str());
            display->setDrawColor(1);

        }

    } while (display->nextPage());

    switch (navigation->get_action())
    {
    case A_BACK:
        sysUi->setUi("Menu");
        break;
    case A_DOWN:
        if (control_position < 6 - 1)
        {
            control_position++;
        }
        break;
    case A_UP:
        if (control_position > 0)
        {
            control_position--;
        }
        break;
    case A_SELECT:
        if (!disable_sending)
        {
            Serial.println("command" + String(control_position));
            String msg = "{\"action\":\"send\",\"data\":{\"action\":\"connect\"}}";
            if (strcmp(sysServices->sendMsg("ServiceMQTT", msg).c_str(), "{\"data\":1}") == 0)
            {
                sysServices->sendMsg("ServiceControlMQTT", "{\"action\":\"send\",\"data\":{\"control\":\"command" + String(control_position) + "\"}}");
                send_message = true;
                t_send_message = millis();
                disable_sending = true;
            }
        }
        break;
    }
}