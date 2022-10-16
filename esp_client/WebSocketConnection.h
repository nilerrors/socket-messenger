#include <ArduinoWebsockets.h>

#include "WebSocketServer.h"

class WebSocketConnection {
 private:
  static void onMessageCallback(websockets::WebsocketsMessage message) {
    Serial.println(message.data());
  }

  static void onEventsCallback(websockets::WebsocketsEvent event, String data) {
    if (event == websockets::WebsocketsEvent::ConnectionOpened) {
      Serial.println("Connnection Opened");
    } else if (event == websockets::WebsocketsEvent::ConnectionClosed) {
      Serial.println("Connnection Closed");
    } else if (event == websockets::WebsocketsEvent::GotPing) {
      Serial.println("Got a Ping!");
    } else if (event == websockets::WebsocketsEvent::GotPong) {
      Serial.println("Got a Pong!");
    }
  }

 public:
  WebSocketServer server;
  websockets::WebsocketsClient client;
  WebSocketConnection(WebSocketServer s, websockets::WebsocketsClient c);
  bool connect();
  bool poll();
  bool send(const websockets::WSInterfaceString &data);
  bool ping(const websockets::WSInterfaceString data);
};
