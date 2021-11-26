#ifndef __SYSTEM_UI_H__
#define __SYSTEM_UI_H__
#include <Arduino.h>

#include <Ui.h>
#include <Navigation.h>
#include <map>

class SystemUi
{
public:
    SystemUi();
    void registerApplications(std::map<String, Ui *> *_application);
    void setUi(String name);
    void pageRender();

private:
    Ui *page;
    std::map<String, Ui *> *application;
    std::map<String, void *> *backgroundProcess;
};

#endif
