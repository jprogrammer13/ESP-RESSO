#include <Arduino.h>
#include <Navigation.h>

Navigation::Navigation(uint8_t _B_BACK, uint8_t _B_SLC, uint8_t _CLK, uint8_t _DT)
{
    this->B_BACK = Button(_B_BACK, true);
    this->B_SLC = Button(_B_SLC, true);
    this->action = A_NONE;
    ESP32Encoder::useInternalWeakPullResistors = UP;
    encoder.attachHalfQuad(_CLK, _DT);
}

void Navigation::begin()
{
    this->B_SLC.begin();
    this->B_BACK.begin();
}

void Navigation::update()
{
    B_SLC.update();
    B_BACK.update();

    states[0] = encoder.getCount();
    states[1] = B_SLC.get_state();
    states[2] = B_BACK.get_state();

    encoder.clearCount();
}

Action Navigation::get_action()
{
    Action tmp_action = A_NONE;
    if (states[0] > 1)
    {
        tmp_action = A_DOWN;
    }
    else if (states[0] < -1)
    {
        tmp_action = A_UP;
    }
    else
    {
        // Check SELECT button
        switch (states[1])
        {
        case 1:
            tmp_action = A_SELECT;
            break;
        case 2:
            tmp_action = A_SELECT_LONG;
            break;
        case 0:
            // Check BACK button
            switch (states[2])
            {
            case 1:
                tmp_action = A_BACK;
                break;
            case 2:
                tmp_action = A_BACK_LONG;
                break;
            }
            break;
        }
    }
    return tmp_action;
}
