#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <json.h>

#include <csignal>

#include "multi-call.h"

DEF_MAIN("logger") {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;
  using namespace seasocks;

  Stub<CoreService> core(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  core.connected >> [&](ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
      core.Log.attach() >> [](int level, std::string const &tag, std::string const &content) {
        std::cout << makeMap("level", level, "tag", tag, "content", content) << std::endl;
      };
    } else {
      fprintf(stderr, "disconnected!\n");
      core.Log.detach();
      core.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
  return 0;
}
