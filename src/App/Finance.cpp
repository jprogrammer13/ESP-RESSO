#include <Arduino.h>
#include <App.h>
#include <App/Finance.h>

Finance::Finance(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    first_time = true;
    y_position = 0;
}

void Finance::draw()
{
    if (first_time)
    {
        display->firstPage();
        do
        {
            for (int i = 0; i < 3; i++)
            {
                display->setDrawColor(1);
                display->drawBox(0, 0, 128, 64);
                display->setDrawColor(0);
                display->setFont(u8g2_font_7x14_tf);
                display->drawStr(5, 39, "Getting the data");
                display->setDrawColor(1);
            }

        } while (display->nextPage());
        // CHIAMATA AI DATI
        String msg = "{\"action\":\"get\"}";
        String response = sysServices->sendMsg("ServiceFinance", msg);

        DynamicJsonDocument doc(512);

        DeserializationError error = deserializeJson(doc, response);

        if (!error)
        {
            JsonObject data = doc["data"];
            JsonArray data_coin_id = data["coin_id"];
            JsonArray data_coin_name = data["coin_name"];
            JsonArray data_price = data["price"];
            JsonArray data_change = data["change"];

            for (int i = 0; i < 3; i++)
            {
                this->coin_id[i] = data_coin_id[i].as<String>();
                this->coin_name[i] = data_coin_name[i].as<String>();
                this->coin_price[i] = data_price[i].as<long>();
                this->coin_price_change[i] = data_change[i].as<float>();
            }

            first_time = false;
        }
        else
        {
            first_time = true;
        }
    }
    display->firstPage();
    do
    {
        for (int i = 0; i < 3; i++)
        {
            display->setDrawColor(1);
            display->drawBox(0, y_position + (50 * i), 128, 20);
            display->setDrawColor(0);
            display->setFont(u8g2_font_fur11_tf);
            display->drawStr(5, y_position + 17 + (50 * i), coin_name[i].c_str());
            display->setFont(u8g2_font_unifont_t_symbols);
            display->drawGlyph(100, y_position + 18 + (50 * i), (coin_price_change[i] > 0) ? 0x2197 : 0x2198);
            display->setFont(u8g2_font_7x14_tf);
            display->setDrawColor(1);
            display->setFont(u8g2_font_7x14_tf);
            // ROUND TO 2 DECIMAL
            float tmp_price = (int)(coin_price[i] * 100 + .5);
            float coin_price = (float)tmp_price / 100;
            display->drawStr(5, y_position + 40 + (50 * i), String(coin_price).c_str());
            String tmp_change = ((coin_price_change[i] > 0) ? "+" : "") + String(coin_price_change[i]);
            display->drawStr(80, y_position + 40 + (50 * i), String(tmp_change).c_str());
        }

    } while (display->nextPage());

    switch (navigation->get_action())
    {
    case A_BACK:
        first_time = true;
        sysUi->setUi("Menu");
        break;
    case A_DOWN:
        if (y_position > -128)
        {
            y_position -= 4;
        }
        break;
    case A_UP:
        if (y_position < 0)
        {
            y_position += 4;
        }
        break;
    case A_SELECT:
        y_position = 0;
        break;
    }
}
