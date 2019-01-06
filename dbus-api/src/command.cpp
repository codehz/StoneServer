#include <dbus-api/CommandService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <csignal>

static simppl::dbus::Dispatcher disp("bus:session");

int main(int argc, char **argv) {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;

	if (argc != 3) return 1;
  
  Stub<CommandService> cmd(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  cmd.connected >> [&] (ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
			cmd.execute(argv[1], argv[2]);
      cmd.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
}
