// config.h
#ifndef CONFIG_H
#define CONFIG_H

// WiFi Configuration
const char* WIFI_SSID = "acts";
const char* WIFI_PASSWORD = "";

// MQTT Broker Configuration
const char* MQTT_BROKER = "3.138.245.113";
const int MQTT_PORT = 1883;
const char* MQTT_CLIENT_ID = "iotnode-01";

// MQTT Broker Credentials
const char* MQTT_USERNAME = "desd";
const char* MQTT_PASSWORD = "desd123";

// MQTT Topics
const char* MQTT_TOPIC_PUBLISH = "cdac/diot/telemetry";
const char* MQTT_TOPIC_SUBSCRIBE = "cdac/`/led/control";

// MAC Address for WiFi Spoofing
//const uint8_t NEW_MAC_ADDRESS[] = {0xc8, 0xb2, 0x9b, 0x70, 0x8a, 0xeb};
const uint8_t NEW_MAC_ADDRESS[] = {0xf4, 0x96, 0x34, 0x9d, 0xe2, 0x61};
#endif
