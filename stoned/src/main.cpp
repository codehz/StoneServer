#include <dbus-api/CommandService.h>
#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <seasocks/PrintfLogger.h>
#include <seasocks/Server.h>

#include <csignal>
#include <memory>

using namespace seasocks;
using namespace simppl::dbus;
using namespace one::codehz::stone;
using namespace std;

static Dispatcher disp("bus:session");

struct StoneHandler : WebSocket::Handler {
  set<WebSocket *> connections;
  Stub<CoreService> &core;
  Stub<CommandService> &command;
  StoneHandler(Stub<CoreService> &core, Stub<CommandService> &command)
      : core(core)
      , command(command) {
    core.connected >> [=](ConnectionState state) {
      if (state == ConnectionState::Connected) {
        this->core.log.attach() >> [=](int const &level, string const &tag, string const &content) {
          for (auto const &conn : this->connections) {
            // broadcast
          }
        };
      } else {
        this->core.log.detach();
      }
    };
  }
  void onConnect(WebSocket *socket) override { connections.insert(socket); }
  void onDisconnect(WebSocket *socket) override { connections.erase(socket); }
  void onData(WebSocket *socket, const char *data) override {
  }
};

int main() {
  Stub<CoreService> core(disp, "default");
  Stub<CommandService> command(disp, "default");
  auto logger = make_shared<PrintfLogger>();
  Server server(logger);
  server.addWebSocketHandler("/", make_shared<StoneHandler>(core, command));
  server.serve("web", 9090);
}