#include "WebSocketConnection.h"

#include <ArduinoWebsockets.h>

WebSocketConnection::WebSocketConnection(WebSocketServer s,
                                         websockets::WebsocketsClient c) {
  this->server = s;
  this->client = c;
}

bool WebSocketConnection::connect() {
  return this->client.connect(this->server.host, this->server.port,
                              this->server.path);
}

bool WebSocketConnection::poll() { return this->client.poll(); }

bool WebSocketConnection::send(const websockets::WSInterfaceString &data) {
  return this->client.send(data);
}

bool WebSocketConnection::ping(const websockets::WSInterfaceString data = "") {
  return this->client.ping(data);
}

void WebSocketConnection::onEvent(const websockets::PartialEventCallback callback) {
  this->client.onEvent(callback);  
}

void WebSocketConnection::onMessage(const websockets::PartialMessageCallback callback) {
  this->client.onMessage(callback);
}
