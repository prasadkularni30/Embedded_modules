/*
 * 
 * This is sample code written for CDAC students of ACTS Batch to work with MQTT protocol
 * Install Library PubSubClient by Nick O'Leary
 * How to Install -> Go to Sketch -> Include Library -> Manage Libraries -> Filter your search -> PubSubClient
 * https://www.arduino.cc/reference/en/libraries/pubsubclient/
 * 
 */
#include <WiFi.h>
#include <PubSubClient.h>  
#include <esp_wifi.h>  

// Set the custom MAC address in case your ESP32 is not regsitered with the acts network - wifi spoofing
uint8_t newMACAddress[] = {0xf4, 0x96, 0x34, 0x9d, 0xe2, 0x16};  // f4:96:34:9d:e2:16

const char* ssid =   "acts";                          //ssid - service set Identifier (Replace it with your ssid name)

const char* password =  "";                     // replace with ssid paasword

const char* mqttBroker = "mqtt3.thingspeak.com";                  // broker address - replace it with your broker address/cloud broker - test.mosquitto.org

const int   mqttPort = 1883;                            // broker port number

const char* clientID = "FA0MLSgZOSwSBDMOKhgbLjU";                   // client-id --> replace it in case willing to connect with same broker
 
const char* mqtt_topic_1 = "channels/2591627/publish/fields/field1"; // topic names

const char* mqtt_topic_2 = "channels/2591627/publish/fields/field2";

const char* mqtt_topic_3 = "channels/2591627/publish/fields/field3";  

WiFiClient MQTTclient;

PubSubClient client(MQTTclient);

long lastReconnectAttempt = 0;
boolean reconnect()
{
  //boolean connect (clientID, [username, password], [willTopic, willQoS, willRetain, willMessage], [cleanSession])
  if (client.connect(clientID,"FA0MLSgZOSwSBDMOKhgbLjU","KR0HvxGETYj4DcWVhB9mQhWG")) {

    Serial.println("Attempting to connect broker");
    
  }
  return client.connected();
}

void setup() {
  Serial.begin(115200);
  Serial.println("Attempting to connect...");
  WiFi.mode(WIFI_STA);      
  esp_wifi_set_mac(WIFI_IF_STA, &newMACAddress[0]); // for wifi spoofing
  WiFi.begin(ssid, password); // Connect to WiFi.
  if (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("Couldn't connect to WiFi.");
  }
  Serial.print("ESP32 IP ADDRESS : ");
  Serial.println(WiFi.localIP());
  //Add details for MQTT Broker
  client.setServer(mqttBroker, mqttPort); // Connect to broker
  lastReconnectAttempt = 0;
}
void loop() {
  if (!client.connected())
  {
    long now = millis();  // Returns the number of milliseconds passed since the Arduino board began running the current program
    if (now - lastReconnectAttempt > 5000) { // Try to reconnect.
      lastReconnectAttempt = now;
      if (reconnect())
      { 
        lastReconnectAttempt = 0;
      }
    }
  }
  else 
  { 
    Serial.println("Connected to Broker --- !!");
    client.loop();
    
    float h = random(0,100);
    float t = random(-16,56);
    int aqi = random(50-100);
    delay(200);


    Serial.println(h);
    Serial.println(t); 
    Serial.println(aqi);
    delay(100);



    client.publish(mqtt_topic_1, String(t).c_str());  //(topicname, payload)
    delay(100);

    client.publish(mqtt_topic_2, String(h).c_str()); 
    delay(100);

    client.publish(mqtt_topic_3, String(aqi).c_str());  //(topicname, payload)
    Serial.println("Message Published");
    delay(200);
  }
}
