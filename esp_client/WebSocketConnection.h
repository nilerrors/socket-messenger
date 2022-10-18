#include <ArduinoWebsockets.h>

#include "WebSocketServer.h"

class WebSocketConnection {
 public:
  WebSocketServer server;
  websockets::WebsocketsClient client;
  WebSocketConnection(WebSocketServer s, websockets::WebsocketsClient c);
  bool connect();
  bool poll();
  bool send(const websockets::WSInterfaceString &data);
  bool ping(const websockets::WSInterfaceString data);
  void onEvent(const websockets::PartialEventCallback callback);
  void onMessage(const websockets::PartialMessageCallback callback);
};
