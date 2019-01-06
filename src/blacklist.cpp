#include <dbus-api/BlacklistService.h>
#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <json.h>

#include <csignal>

static simppl::dbus::Dispatcher disp("bus:session");

enum action { ADD_UUID, ADD_XUID, DEL_UUID, DEL_XUID, ADD_NAME };

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
  } else if (strcmp(argv[1], "add-name") == 0) {
    assert(argc == 4);
    action = ADD_NAME;
  } else {
    fprintf(stderr, "add-uuid|add-xuid|del-uuid|del-xuid\n");
    return 2;
  }

  Stub<BlacklistService> blacklist(disp, "default");
  Stub<CoreService> core(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  blacklist.connected >> [&](ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
      switch (action) {
      case ADD_UUID:
        blacklist.addByUUID(argv[2], argv[3]);
        disp.stop();
        break;
      case ADD_XUID:
        blacklist.addByXUID(argv[2], argv[3]);
        disp.stop();
        break;
      case DEL_UUID:
        blacklist.removeByUUID(argv[2]);
        disp.stop();
        break;
      case DEL_XUID:
        blacklist.removeByXUID(argv[2]);
        disp.stop();
        break;
      case ADD_NAME: {
        fprintf(stderr, "waiting connection(core)...\n");
        core.connected >> [&](ConnectionState state) {
          if (state == ConnectionState::Connected) {
            fprintf(stderr, "connected(core)!\n");
            core.players.get_async() >> [&](CallState call, vector<structs::PlayerInfo> const &vec) {
              for (auto &player : vec) {
                if (player.name == argv[2]) {
                  blacklist.addByUUID(player.uuid, argv[3]);
                  disp.stop();
                  return;
                }
              }
              fprintf(stderr, "playername not found: %s\n", argv[2]);
              disp.stop();
            };
          } else {
            fprintf(stderr, "disconnected(core)!\n");
          }
        };
        break;
      }
      }
    } else {
      fprintf(stderr, "disconnected!\n");
      blacklist.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
}
