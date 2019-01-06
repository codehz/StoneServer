#include <dbus-api/BlacklistService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <json.h>

#include <csignal>

static simppl::dbus::Dispatcher disp("bus:session");

enum action { ADD_UUID, ADD_XUID, DEL_UUID, DEL_XUID };

int main(int argc, char **argv) {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;
  using namespace seasocks;

  assert(argc == 3 || argc == 4);

  action action;

  if (strcmp(argv[1], "add-uuid") == 0) {
    assert(argc == 4);
    action = ADD_UUID;
  } else if (strcmp(argv[1], "add-xuid") == 0) {
    assert(argc == 4);
    action = ADD_XUID;
  } else if (strcmp(argv[1], "del-uuid") == 0) {
    assert(argc == 3);
    action = DEL_UUID;
  } else if (strcmp(argv[1], "del-xuid") == 0) {
    assert(argc == 3);
    action = DEL_XUID;
  } else {
    fprintf(stderr, "add-uuid|add-xuid|del-uuid|del-xuid\n");
    return 2;
  }

  Stub<BlacklistService> blacklist(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  blacklist.connected >> [&](ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
      switch (action) {
        case ADD_UUID: blacklist.addByUUID(argv[2], argv[3]); break;
        case ADD_XUID: blacklist.addByXUID(argv[2], argv[3]); break;
        case DEL_UUID: blacklist.removeByUUID(argv[2]); break;
        case DEL_XUID: blacklist.removeByXUID(argv[2]); break;
      }
    } else {
      fprintf(stderr, "disconnected!\n");
    }
    blacklist.disp().stop();
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
}
