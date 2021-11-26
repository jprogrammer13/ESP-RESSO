#include <Arduino.h>
#include <DHT.h>
#include <System/SystemESPRESSO.h>

SystemESPRESSO sysESPRESSO;

void setup()
{
  Serial.begin(115200);
  sysESPRESSO.begin();
}

void loop()
{
  sysESPRESSO.run();
}