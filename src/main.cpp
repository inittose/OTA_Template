// Шаблон отправления прошивки через OTA и мониторинга через MQTT
#include <Arduino.h>
#include <WiFi.h>
#include "ota.hpp"
#include "mqtt.hpp"

void WiFiSetup(const char *ssid, const char *password);

void setup()
{
  Serial.begin(115200);
  WiFiSetup(ENV::ssid, ENV::password);
  MQTT::setup();
  OTA::setup();
  MQTT::print(WiFi.localIP().toString());
}

void loop()
{
  MQTT::loop();
  OTA::loop();
}

void WiFiSetup(const char *ssid, const char *password)
{
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
  }

  Serial.println(WiFi.localIP());
}