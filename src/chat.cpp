#include <dbus-api/ChatService.h>

#include <simppl/dispatcher.h>
#include <simppl/stub.h>

#include <csignal>

static simppl::dbus::Dispatcher disp("bus:session");

int main() {
  using namespace simppl::dbus;
  using namespace one::codehz::stone;
  
  Stub<ChatService> chat(disp, "default");
  printf("waiting connection...\n");
  chat.connected >> [&] (ConnectionState state) {
    if (state == ConnectionState::Connected) {
      printf("connected!\n");
      chat.recv.attach() >> [](std::string const &sender, std::string const &content) {
        printf("<%s> %s\n", sender.c_str(), content.c_str());
      };
    } else {
      printf("disconnected!\n");
      chat.recv.detach();
      chat.disp().stop();
    }
  };
  std::signal(SIGINT, [](int) { disp.stop(); });
  std::signal(SIGTERM, [](int) { disp.stop(); });
  disp.run();
}
