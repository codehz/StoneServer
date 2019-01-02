#include <dbus-api/ChatService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <csignal>

static simppl::dbus::Dispatcher disp("bus:session");

int main(int argc, char **argv) {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;

	if (argc != 3) return 1;
  
  Stub<ChatService> chat(disp, "default");
  printf("waiting connection...\n");
  chat.connected >> [&] (ConnectionState state) {
    if (state == ConnectionState::Connected) {
      printf("connected!\n");
			chat.send(argv[1], argv[2]);
      chat.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
}
