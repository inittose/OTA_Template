#pragma once
#include <ArduinoOTA.h>

/// @brief Хранит логику включения встроенной OTA (Over-The-Air update).
/// @details Для работы вызовите setup/loop в соответствующих функциях.
namespace OTA
{
    void setup();
    void loop();
} // namespace OTA