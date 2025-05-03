#include "ota.hpp"

namespace OTA
{
    void setup()
    {
        ArduinoOTA
        .onStart([]()
        {
            String type = ArduinoOTA.getCommand() == U_FLASH ? "sketch" : "filesystem";
            Serial.println("Start updating " + type);
        })
        .onEnd([]()
        {
            Serial.println("\nEnd");
        })
        .onProgress([](unsigned int progress, unsigned int total)
        {
            Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
        })
        .onError([](ota_error_t error)
        {
            Serial.printf("Error[%u]: ", error);
        });

        ArduinoOTA.begin();
    }

    void loop()
    {
        ArduinoOTA.handle();
    }
} // namespace OTA
