#include <dbus-api/ChatService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <csignal>

#include "multi-call.h"

static simppl::dbus::Dispatcher disp("bus:session");

DEF_MAIN("chat-send") {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;

	if (argc != 3) return 1;
  
  Stub<ChatService> chat(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  chat.connected >> [&] (ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
			chat.Send(argv[1], argv[2]);
      chat.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
  return 0;
}
