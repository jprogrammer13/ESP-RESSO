#include <Arduino.h>
#include <App.h>
#include <App/Menu.h>

Menu::Menu(Navigation *_navigation, Display *_display, SystemUi *_sysUi, SystemServices *_sysService) : App(_navigation, _display, _sysUi, _sysService)
{
    position = 0;
    applications.insert(std::pair<String, int>("Test", 0x23f0));

    n_applications = applications.size();
}

void Menu::draw()
{
    auto iterator = applications.begin();
    std::advance(iterator, this->position);

    display->firstPage();
    do
    {
        display->setFont(u8g2_font_unifont_t_symbols);
        display->drawGlyph(20, 20, iterator->second);
        display->setFont(u8g2_font_7x14_tf);
        display->setCursor(40, 40);
        display->print(iterator->first);

    } while (display->nextPage());

    switch (navigation->get_action())
    {
    case A_DOWN:
        if (position < n_applications-1)
        {
            position++;
        }
        break;
    case A_UP:
        if (position > 0)
        {
            position--;
        }
        break;
    case A_SELECT:
        sysUi->setUi(iterator->first);
        break;
    case A_BACK:
        sysUi->setUi("Home");
        break;
    }
}