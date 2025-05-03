#pragma once
#include <WiFi.h>
#include <Arduino.h>
#include <PubSubClient.h>

/// @brief Хранит глобальные переменные среды.
/// @details Обязательно поменять значения переменных, перед компиляцией скетча.
namespace ENV
{
    extern const char *ssid;
    extern const char *password;

    extern const char *mqtt_broker;
    extern const char *topic_debug;
    extern const char *mqtt_username;
    extern const char *mqtt_password;
    extern const int mqtt_port;

    extern WiFiClient espClient;
    extern PubSubClient client;
} // namespace ENV
