#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <csignal>

static simppl::dbus::Dispatcher disp("bus:session");

int main() {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;
  
  Stub<CoreService> core(disp, "default");
  printf("waiting connection...\n");
  core.connected >> [&] (ConnectionState state) {
    if (state == ConnectionState::Connected) {
      printf("connected!\n");
      core.players.attach() >> [](CallState call, vector<structs::PlayerInfo> const&vec) {
        printf("userlist updated: [%d]\n", vec.size());
        for (auto &info : vec) {
          printf("\t{name: %s, uuid: %s, xuid: %s}\n", info.name.c_str(), info.uuid.c_str(), info.xuid.c_str());
        }
      };
    } else {
      printf("disconnected!\n");
      core.players.detach();
      core.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
}