#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <seasocks/PrintfLogger.h>
#include <seasocks/Server.h>

#include <msgpack.hpp>

#include <csignal>
#include <memory>

using namespace seasocks;
using namespace std;

struct WSCommand {
  string name, content;
  MSGPACK_DEFINE(name, content);
};

struct StoneHandler : WebSocket::Handler {
  set<WebSocket *> connections;
  void onConnect(WebSocket *socket) override { connections.insert(socket); }
  void onDisconnect(WebSocket *socket) override { connections.erase(socket); }
  void onData(WebSocket *socket, const char *data) override {
    auto handle = msgpack::unpack(data, -1);
    WSCommand command;
    try {
      handle.get().convert(command);
      printf("%s: %s\n", command.name.c_str(), command.content.c_str());
    } catch (bad_cast e) {
      printf("error in cast: %s\n", e.what());
      socket->close();
    }
  }
};

int main() {
  auto logger = make_shared<PrintfLogger>();
  Server server(logger);
  server.addWebSocketHandler("/", make_shared<StoneHandler>());
  server.serve("web", 9090);
}