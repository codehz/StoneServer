#include <dbus-api/ChatService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <json.h>

#include <csignal>

static simppl::dbus::Dispatcher disp("bus:session");

int main() {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;
  using namespace seasocks;
  
  Stub<ChatService> chat(disp, "default");
  fprintf(stderr, "waiting connection...\n");
  chat.connected >> [&] (ConnectionState state) {
    if (state == ConnectionState::Connected) {
      fprintf(stderr, "connected!\n");
      chat.Receive.attach() >> [](std::string const &sender, std::string const &content) {
        std::cout << makeMap("sender", sender, "content", content) << std::endl;
      };
    } else {
      fprintf(stderr, "disconnected!\n");
      chat.Receive.detach();
      chat.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
}
