#include <Arduino.h>
#include <WiFi.h>
#include "sMQTTBroker.h"

const char* WIFI_SSID = "brisa-3091372";
const char* WIFI_PASSWORD = "teskdl6u";
const unsigned short MQTT_PORT = 1883;

sMQTTBroker broker;

//IPAddress local_IP(192, 168, 0, 3); // 192.168.0.3
//IPAddress gateway(192, 168, 0, 1); // router IP gateway
//IPAddress subnet(255, 255, 0, 0); // subnet mask

void connect_to_wifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  Serial.println("Connected to wifi");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);

  delay(5000);

  connect_to_wifi();

  broker.init(MQTT_PORT);
  Serial.println("broker was initialized");

  //if (!WiFi.config(local_IP, gateway, subnet)) {
    //Serial.println("Failed to configure wifi connection");
  //}
}

void loop() {
  delay(1000);
  broker.update();
  Serial.println("broker updated");
}