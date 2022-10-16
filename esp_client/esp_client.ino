#include <WiFi.h>

#include "WebSocketConnection.h"

const char* ssid = "Proximus-Home-038934";
const char* password = "ubs67anbm4nckf3f";

WebSocketServer server = {"192.168.129.7", 8000, "/ws/thisiscrazy"};
websockets::WebsocketsClient client;
WebSocketConnection connection(server, client);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to Wifi");
  for (int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
    Serial.print(".");
    delay(1000);
  }

  connection.connect();
  connection.send("Hello World");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    connection.poll();

  } else {
    Serial.println("Wifi disconnected!");
    delay(3000);
  }
}