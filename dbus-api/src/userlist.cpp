#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <json.h>

#include <csignal>

static simppl::dbus::Dispatcher disp("bus:session");

using namespace simppl::dbus;
using namespace one::codehz::stone;
using namespace seasocks;

void structs::PlayerInfo::jsonToStream(std::ostream &str) const { str << makeMap("name", name, "uuid", uuid, "xuid", xuid); }

int main() {
  Stub<CoreService> core(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  core.connected >> [&](ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
      core.players.attach() >> [](CallState call, vector<structs::PlayerInfo> const &vec) {
        std::cout << makeMap("size", vec.size(), "list", makeArrayFromContainer(vec)) << std::endl;
      };
    } else {
      fprintf(stderr, "disconnected!\n");
      core.players.detach();
      core.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
}