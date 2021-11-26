#include <Arduino.h>
#include <System/SystemUi.h>

SystemUi::SystemUi(){};

void SystemUi::registerApplications(std::map<String, Ui *> *_application)
{
    this->application = _application;
}

void SystemUi::setUi(String name)
{
    this->page = (*application)[name];
}

void SystemUi::pageRender()
{
    this->page->draw();
}