#include <ArduinoWebsockets.h>
#include "WebSocketConnection.h"


WebSocketConnection::WebSocketConnection(WebSocketServer s, websockets::WebsocketsClient c) {
	this->server = s;
	this->client = c;

	this->client.onMessage(this->onMessageCallback);
	this->client.onEvent(this->onEventsCallback);
}

bool WebSocketConnection::connect() {
	return this->client.connect(this->server.host, this->server.port, this->server.path);  
}

bool WebSocketConnection::poll() {
	return this->client.poll();  
}

bool WebSocketConnection::send(const websockets::WSInterfaceString &data) {
	return this->client.send(data);
}

bool WebSocketConnection::ping(const websockets::WSInterfaceString data = "") {
	return this->client.ping(data);
}
