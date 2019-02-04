#include <stone-api/Core.h>

int main() {
  using namespace api;
  apid_init();

  CoreService<ClientSide> core;
  core.log >> [](auto entry) {
    auto [tag, level, content] = entry;
    printf("%d [%s] %s\n", level, tag.c_str(), content.c_str());
  };
  core.config >> [](auto cfg) { printf("config: %s\n", cfg.c_str()); };
  core.ping({}, [](auto) { printf("pong!"); });
  core.stop({}, [] { apid_stop(); });

  apid_start();
}