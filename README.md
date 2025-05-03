# Шаблон OTA + MQTT для ESP32

## Настройка
Перед запуском в файле `src/environment.cpp` обязательно поменяйте значения на свои. 

> Этот файл хранит переменные среды, такие как: логин/пароль от WiFi, входные данные для MQTT.

Чтобы получить доступ к переменным окружения обратитесь к пространству имен `ENV`:
```cpp
WiFiSetup(ENV::ssid, ENV::password);
```

## Функции пространства имен MQTT
`print` - отправляет сообщения в текстовом формате на топик отладки *(по-умолчанию `debug`)* и в Serial monitor. Пример:
```cpp
MQTT::print(WiFi.localIP().toString());
```

`send` - отправка сообщения в виде json на заданный топик. На вход подаем имя топика и объект JsonDocument:
```cpp
JsonDocument doc;
doc["Value"] = "someValue";
MQTT::send("esp32/data", doc)
// На топик esp32/data отправится:
// {
//     "Value": "someValue"
// }
```