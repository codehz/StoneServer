#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <json.h>

#include <csignal>

#include "multi-call.h"

static simppl::dbus::Dispatcher disp("bus:session");

using namespace simppl::dbus;
using namespace one::codehz::stone;
using namespace seasocks;

void structs::PlayerInfo::jsonToStream(std::ostream &str) const { str << makeMap("name", name, "uuid", uuid, "xuid", xuid); }

DEF_MAIN("userlist") {
  Stub<CoreService> core(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  core.connected >> [&](ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
      core.Players.attach() >> [](CallState call, vector<structs::PlayerInfo> const &vec) {
        std::cout << makeMap("type", "list", "size", vec.size(), "list", makeArrayFromContainer(vec)) << std::endl;
      };
      core.PlayerAdded.attach() >> [](structs::PlayerInfo const &info) {
        std::cout << makeMap("type", "joined", "target", info) << std::endl;
      };
      core.PlayerRemoved.attach() >> [](structs::PlayerInfo const &info) {
        std::cout << makeMap("type", "left", "target", info) << std::endl;
      };
    } else {
      fprintf(stderr, "disconnected!\n");
      core.Players.detach();
      core.PlayerAdded.detach();
      core.PlayerRemoved.detach();
      core.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
  return 0;
}