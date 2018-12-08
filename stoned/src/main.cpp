#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <csignal>

#include <seasocks/PrintfLogger.h>
#include <seasocks/Server.h>

#include <memory>

using namespace seasocks;
using namespace std;

struct StoneHandler : WebSocket::Handler {
  set<WebSocket *> connections;
  void onConnect(WebSocket *socket) override { connections.insert(socket); }
  void onDisconnect(WebSocket *socket) override { connections.erase(socket); }
  void onData(WebSocket *socket, const char *data) override {}
};

int main() {
  auto logger = make_shared<PrintfLogger>();
  Server server(logger);
  server.addWebSocketHandler("/ws", make_shared<StoneHandler>());
  server.serve("web", 9090);
}