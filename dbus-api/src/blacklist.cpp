#include <dbus-api/BlacklistService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <json.h>

#include <csignal>

static simppl::dbus::Dispatcher disp("bus:session");

enum action { ADD_UUID, ADD_XUID, ADD_NAME, DEL_UUID, DEL_XUID, KICK_UUID, KICK_XUID, KICK_NAME };

void xassert(bool value, int code, char const *message) {
  if (!value) {
    fprintf(stderr, "%s\n", message);
    exit(code);
  }
}

int main(int argc, char **argv) {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;
  using namespace seasocks;
  int retval = 0;

  xassert(argc == 3 || argc == 4, 1, "argc need to be 3 or 4");

  action action;

  if (strcmp(argv[1], "add-uuid") == 0) {
    xassert(argc == 4, 1, "argc need to be 4");
    action = ADD_UUID;
  } else if (strcmp(argv[1], "add-xuid") == 0) {
    xassert(argc == 4, 1, "argc need to be 4");
    action = ADD_XUID;
  } else if (strcmp(argv[1], "del-uuid") == 0) {
    xassert(argc == 3, 1, "argc need to be 3");
    action = DEL_UUID;
  } else if (strcmp(argv[1], "del-xuid") == 0) {
    xassert(argc == 3, 1, "argc need to be 3");
    action = DEL_XUID;
  } else if (strcmp(argv[1], "add-name") == 0) {
    xassert(argc == 4, 1, "argc need to be 4");
    action = ADD_NAME;
  } else if (strcmp(argv[1], "kick-uuid") == 0) {
    xassert(argc == 4, 1, "argc need to be 4");
    action = KICK_UUID;
  } else if (strcmp(argv[1], "kick-xuid") == 0) {
    xassert(argc == 4, 1, "argc need to be 4");
    action = KICK_XUID;
  } else if (strcmp(argv[1], "kick-name") == 0) {
    xassert(argc == 4, 1, "argc need to be 4");
    action = KICK_NAME;
  } else {
    fprintf(stderr, "add-uuid|add-xuid|add-name|kick-uuid|kick-xuid|kick-name|del-uuid|del-xuid\n");
    return 2;
  }

  Stub<BlacklistService> blacklist(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  blacklist.connected >> [&](ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
      try {
        switch (action) {
        case ADD_UUID: blacklist.AddByUUID(argv[2], argv[3]); break;
        case ADD_XUID: blacklist.AddByXUID(argv[2], argv[3]); break;
        case ADD_NAME: blacklist.AddByName(argv[2], argv[3]); break;
        case KICK_UUID: blacklist.KickByUUID(argv[2], argv[3]); break;
        case KICK_XUID: blacklist.KickByXUID(argv[2], argv[3]); break;
        case KICK_NAME: blacklist.KickByName(argv[2], argv[3]); break;
        case DEL_UUID: blacklist.RemoveByUUID(argv[2]); break;
        case DEL_XUID: blacklist.RemoveByXUID(argv[2]); break;
        }
      } catch (Error &e) {
        fprintf(stderr, "%s\n", e.what());
        retval = 2;
      }
    } else {
      fprintf(stderr, "disconnected!\n");
    }
    disp.stop();
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
  return retval;
}
