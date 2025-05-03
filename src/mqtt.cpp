#include "mqtt.hpp"

namespace MQTT
{
    const char *mqtt_broker = ENV::mqtt_broker;
    const char *topic_debug = ENV::topic_debug;
    const char *mqtt_username = ENV::mqtt_username;
    const char *mqtt_password = ENV::mqtt_password;
    const int mqtt_port = ENV::mqtt_port;

    WiFiClient espClient;
    PubSubClient client(espClient);

    void setup()
    {
        client.setServer(mqtt_broker, mqtt_port);
        client.setCallback(callback);
        while (!client.connected())
        {
            String client_id = "esp32-client-";
            client_id += String(WiFi.macAddress());
            Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
            if (client.connect(client_id.c_str(), mqtt_username, mqtt_password))
            {
                Serial.println("Public EMQX MQTT broker connected");
            }
            else
            {
                Serial.print("failed with state ");
                Serial.print(client.state());
                delay(2000);
            }
        }

        print("ESP32 connected");
    }

    void loop()
    {
        client.loop();
    }

    void print(const char *message)
    {
        client.publish(topic_debug, message);
    }

    void print(const String& message)
    {
        client.publish(topic_debug, message.c_str());
    }

    void send(const char *topic, const JsonDocument& doc)
    {
        String json;
        serializeJsonPretty(doc, json);
        client.publish(topic, json.c_str());
    }

    void callback(char *topic, byte *payload, unsigned int length)
    {
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, payload);
        if(error)
        {
            Serial.print(F("deserializeJson failed: "));
            Serial.println(error.f_str());
            return;
        }
    }
}
