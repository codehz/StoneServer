#include <dbus-api/CommandService.h>
#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <seasocks/PrintfLogger.h>
#include <seasocks/Server.h>
#include <seasocks/util/CrackedUriPageHandler.h>
#include <seasocks/util/Json.h>
#include <seasocks/util/PathHandler.h>
#include <seasocks/util/RootPageHandler.h>

#include <csignal>
#include <memory>
#include <thread>

using namespace seasocks;
using namespace simppl::dbus;
using namespace one::codehz::stone;
using namespace std;

static Dispatcher disp("bus:session");

void structs::PlayerInfo::jsonToStream(std::ostream &str) const { str << makeMap("name", name, "uuid", uuid, "xuid", xuid); }
void structs::AutoCompleteOption::jsonToStream(std::ostream &str) const {
  str << makeMap("source", source, "title", title, "description", desc, "offset", offset, "length", length, "item_id", item);
}

struct StoneHandler : WebSocket::Handler {
  set<WebSocket *> connections;
  Server &server;
  Stub<CoreService> &core;
  Stub<CommandService> &command;
  StoneHandler(Server &_server, Stub<CoreService> &_core, Stub<CommandService> &_command)
      : server(_server)
      , core(_core)
      , command(_command) {
    core.connected >> [&](ConnectionState state) {
      if (state != ConnectionState::Connected) return;
      core.log.attach() >> [this](int const &level, string const &tag, string const &content) {
        server.execute([this, ret = makeMap("type", "log", "level", level, "tag", tag, "content", content)] {
          for (auto const &conn : connections) { conn->send(ret); }
        });
      };
      core.players.attach() >> [this](CallState state, vector<structs::PlayerInfo> const &vec) {
        server.execute([this, ret = makeMap("type", "player_list", "list", makeArrayFromContainer(vec))] {
          for (auto const &conn : connections) { conn->send(ret); }
        });
      };
    };
  }
  void onConnect(WebSocket *socket) override { connections.insert(socket); }
  void onDisconnect(WebSocket *socket) override { connections.erase(socket); }
  void onData(WebSocket *socket, const uint8_t *, size_t) override { socket->send(makeMap("type", "error", "details", "Unsupported")); }
  void onData(WebSocket *socket, const char *) override { socket->send(makeMap("type", "error", "details", "Unsupported")); }
};

struct CommandHandler : CrackedUriPageHandler {
  Stub<CommandService> &command;
  CommandHandler(Stub<CommandService> &_command)
      : command(_command) {}
  shared_ptr<Response> handle(const CrackedUri &uri, const Request &request) override {
    if (request.verb() == Request::Verb::Post && uri.path().size() == 1 && request.contentLength() < 2048) {
      auto &front = uri.path().front();
      string body{(char const*)request.content(), request.contentLength()};
      if (body.empty()) return Response::jsonResponse(makeMap("type", "error", "details", "Body is required"));
      if (front == "execute") {
        auto origin = uri.queryParam("origin", "web");
        if (origin.empty()) return Response::jsonResponse(makeMap("type", "error", "details", "Origin shouldn't be empty"));
        auto result = command.execute(origin, body);
        return Response::jsonResponse(makeMap("type", "result/execute", "content", result.c_str()));
      } else if (front == "complete") {
        auto position = uri.queryParam("pos", "-1");
        int pos;
        try {
          pos = stoi(position, nullptr, 10);
        } catch (invalid_argument &arg) { return Response::jsonResponse(makeMap("type", "error", "details", "Cannot convert the pos")); }
        auto result = command.complete(body, (unsigned)pos);
        return Response::jsonResponse(makeMap("type", "result/complete", "list", makeArrayFromContainer(result)));
      }
    }
    return Response::jsonResponse(makeMap("type", "error", "details", "Unsupported"));
  }
};

int main() {
  Stub<CoreService> core(disp, "default");
  Stub<CommandService> command(disp, "default");
  thread dispThread{ [] { disp.run(); } };
  auto logger = make_shared<PrintfLogger>();
  Server server(logger);
  server.addWebSocketHandler("/ws", make_shared<StoneHandler>(server, core, command), true);
  auto root = make_shared<RootPageHandler>();
  root->add(make_shared<PathHandler>("api", make_shared<PathHandler>("v1", make_shared<PathHandler>("command", make_shared<CommandHandler>(command)))));
  server.addPageHandler(root);
  server.serve("web", 9090);
  disp.stop();
}