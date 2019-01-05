#include <dbus-api/CoreService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <csignal>

static simppl::dbus::Dispatcher disp("bus:session");

int main() {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;
  
  Stub<CoreService> core(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  core.connected >> [&] (ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
      core.log.attach() >> [](int level, std::string const &tag, std::string const &content) {
        printf("%d [%s] %s\n", level, tag.c_str(), content.c_str());
      };
    } else {
      fprintf(stderr, "disconnected!\n");
      core.log.detach();
      core.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
}
