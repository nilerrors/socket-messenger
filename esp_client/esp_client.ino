#include <WiFi.h>

#include "WebSocketConnection.h"

const char* ssid = "Proximus-Home-038934";
const char* password = "ubs67anbm4nckf3f";

WebSocketServer server = {"192.168.129.7", 8000, "/ws/thisiscrazy"};
websockets::WebsocketsClient client;
WebSocketConnection connection(server, client);

long int messages = 0;
long int events = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to Wifi");
  for (int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
    Serial.print(".");
    delay(1000);
  }


  connection.onMessage([&](websockets::WebsocketsMessage message) {
    messages++;
    Serial.println(message.data());
  });

  connection.onEvent([&](websockets::WebsocketsEvent event, String data) {
    events++;
    if (event == websockets::WebsocketsEvent::ConnectionOpened) {
      Serial.println("Connnection Opened");
    } else if (event == websockets::WebsocketsEvent::ConnectionClosed) {
      Serial.println("Connnection Closed");
    } else if (event == websockets::WebsocketsEvent::GotPing) {
      Serial.println("Got a Ping!");
    } else if (event == websockets::WebsocketsEvent::GotPong) {
      Serial.println("Got a Pong!");
    }
  });

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