#pragma once
#include "environment.hpp"
#include "ArduinoJson.h"
#include <functional>

namespace MQTT
{
    extern WiFiClient espClient;
    extern PubSubClient client;

    void setup();
    void loop();
    void callback(char *topic, byte *payload, unsigned int length);

    /// @brief Отправляет сообщение в топик отладки (по-умолчанию: debug).
    /// @param message Сообщение отладки.
    void print(const char *message);

    /// @brief Отправляет сообщение в топик отладки (по-умолчанию: debug).
    /// @param message Сообщение отладки.
    void print(const String& message);

    /// @brief Отправляет сообщение в топик.
    /// @param topic Имя топика.
    /// @param doc JSON документ.
    void send(const char *topic, const JsonDocument& doc);
} // namespace MQTT