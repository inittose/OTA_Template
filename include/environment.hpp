#pragma once
#include <WiFi.h>
#include <Arduino.h>
#include <PubSubClient.h>

/// @brief Хранит глобальные переменные среды.
/// @details Обязательно поменять значения переменных, перед компиляцией скетча.
namespace ENV
{
    /// @brief Название сети WiFi.
    extern const char *ssid;

    /// @brief Пароль сети WiFi.
    extern const char *password;

    /// @brief IP адрес/домен mqtt брокера.
    extern const char *mqtt_broker;

    /// @brief Топик отладки (по-умолчанию: debug).
    extern const char *topic_debug;

    /// @brief Логин аккаунта mqtt брокера.
    extern const char *mqtt_username;

    /// @brief Пароль аккаунта mqtt брокера.
    extern const char *mqtt_password;

    /// @brief Порт mqtt брокера (по-умолчанию: 1883).
    extern const int mqtt_port;

    /// @brief Пароль обновления прошивки через OTA (по-умолчанию без пароля).
    /// @details После выставления пароля, не забудьте указать его в platformio.ini -> upload_flags.
    extern const char *ota_password;
} // namespace ENV
