#ifndef __CONFIG_H__
#define __CONFIG_H__
// CONFIG OF I/O PORT
#define DHT11_PIN 27
#define RELAY_PIN 26

#define B_BACK_PIN 4
#define B_SLC_PIN 12
#define ENCODER_CLK_PIN 21
#define ENCODER_DT_PIN 22

#define DISPLAY_CLOCK_PIN 18
#define DISPLAY_DATA_PIN 23
#define DISPLAY_CS_PIN 5

// SOFTWARE CONFIGURATION

// ########################
// ADAFRUIT
#define ADAFRUIT_USERNAME "Riccardo136"
#define ADAFRUIT_SERVER "io.adafruit.com"
#define ADAFRUIT_SERVER_PORT 8883
#define ADAFRUIT_API_KEY "c6056b140d174bdfbe55d6fb637e8695"

// WIFI
#define WIFI_SSID "FRITZ!Box 7490"
#define WIFI_PSWD "RiccardoBussola13"

// TIME
#define NTP_SERVER_URL "0.it.pool.ntp.org"
#define GMT_OFFSET 3600
#define LIGHT_OFFSET 3600

// WEATHER
#define WEATHER_API_KEY "6f3d3af7da198e596a118561c69807db"
#define CITY "Verona"

// COINRANKING
#define FINANCE_API_KEY "coinranking41751c93cd1d35e5d699682b5fb5b08cd3461f4fd4e8153a"

#endif