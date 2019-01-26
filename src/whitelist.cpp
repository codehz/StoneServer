#include <dbus-api/WhitelistService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <json.h>

#include <csignal>

#include "multi-call.h"

static simppl::dbus::Dispatcher disp("bus:session");

enum action { RELOAD, DUMP };

void xassert(bool value, int code, char const *message) {
  if (!value) {
    fprintf(stderr, "%s\n", message);
    exit(code);
  }
}

DEF_MAIN("whitelist") {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;
  using namespace seasocks;
  int retval = 0;

  xassert(argc == 2, 1, "argc need to be 2");

  action action;

  if (strcmp(argv[1], "reload") == 0) {
    action = RELOAD;
  } else if (strcmp(argv[1], "dump") == 0) {
    action = DUMP;
  } else {
    fprintf(stderr, "reload|save\n");
    return 2;
  }

  Stub<WhitelistService> whitelist(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  whitelist.connected >> [&](ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
      try {
        switch (action) {
        case RELOAD: whitelist.Reload(); break;
        case DUMP: whitelist.Dump(); break;
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
