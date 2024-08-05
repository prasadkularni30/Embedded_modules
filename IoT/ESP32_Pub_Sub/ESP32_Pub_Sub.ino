/*
 * This is sample code written to work with MQTT protocol
 * Install Library PubSubClient by Nick O'Leary
 * How to Install -> Go to Sketch -> Include Library -> Manage Libraries -> Filter your search -> PubSubClient
 * Arduino JSON by Benoit Blanchon
 * https://www.arduino.cc/reference/en/libraries/pubsubclient/
 * https://www.arduino.cc/reference/en/libraries/wifi/
 */

#include <WiFi.h>
#include <PubSubClient.h>
#include <esp_wifi.h>
#include <ArduinoJson.h>
#include "config.h" // Include the configuration file

DynamicJsonDocument sensor_data_payload(1024);
char sensor_data_format_for_mqtt_publish[1024];

WiFiClient MQTTclient;
PubSubClient client(MQTTclient);

long lastReconnectAttempt = 0;

// Function to handle reconnection to the MQTT broker
boolean reconnect() {
  // Attempt to connect to the MQTT broker with client ID and credentials
  //if (client.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    if (client.connect(MQTT_CLIENT_ID)) {
    Serial.println("Attempting to connect to broker");
    client.subscribe(MQTT_TOPIC_SUBSCRIBE); // Subscribe to the LED control topic
  }
  return client.connected();
}

// Function to handle incoming MQTT messages
void handleIncomingMessage(char* topic, byte* payload, unsigned int length) {
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  Serial.println(message);

  // Control the LED based on the message received
  if (String(topic) == MQTT_TOPIC_SUBSCRIBE) {
    if (message == "1") {
      digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on
    } else if (message == "0") {
      digitalWrite(LED_BUILTIN, LOW); // Turn the LED off
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Attempting to connect to WiFi...");
  WiFi.mode(WIFI_STA);
  esp_wifi_set_mac(WIFI_IF_STA, &NEW_MAC_ADDRESS[0]); // For WiFi spoofing
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // Connect to WiFi
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Couldn't connect to WiFi.");
  }
  Serial.print("ESP32 IP ADDRESS: ");
  Serial.println(WiFi.localIP());
  String macAddress = WiFi.macAddress();
  // Print the MAC address to the Serial Monitor
  Serial.println("MAC Address: " + macAddress);
  client.setServer(MQTT_BROKER, MQTT_PORT); // Connect to broker
  client.setCallback(handleIncomingMessage); // Set the callback function for incoming messages
  lastReconnectAttempt = 0;

  pinMode(LED_BUILTIN, OUTPUT); // Initialize the built-in LED pin as an output
}

void loop() {
  if (!client.connected()) {
    long now = millis();  // Returns the number of milliseconds passed since the Arduino board began running the current program
    if (now - lastReconnectAttempt > 5000) { // Try to reconnect every 5 seconds
      lastReconnectAttempt = now;
      if (reconnect()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    Serial.println("Connected to Broker --- !!");
    client.loop();

    // Generate random sensor data
    float humidity = random(0, 100);
    float temperature = random(-16, 56);

    // Populate the JSON payload with sensor data
    sensor_data_payload["temperature"] = temperature;
    sensor_data_payload["humidity"] = humidity;

    // Serialize JSON payload to a char array
    serializeJson(sensor_data_payload, sensor_data_format_for_mqtt_publish);

    delay(2000);
    Serial.println("Humidity: " + String(humidity));
    Serial.println("Temperature: " + String(temperature));
    client.publish(MQTT_TOPIC_PUBLISH, sensor_data_format_for_mqtt_publish);  // Publish sensor data to MQTT topic
    Serial.println("Sensor data sent to broker");
    delay(5000);
  }
}
