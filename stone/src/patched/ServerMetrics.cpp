#include "../patched.h"
#include <minecraft/ServerInstance.h>
#include <stone/server_hook.h>

namespace {

SHook(void, _ZN16EducationOptions4initERK9LevelData, void *self, void *data) {
  printf("%p %p\n", self, data);
  asm("int3");
  original(self, data);
}

SInstanceHook(void, _ZN13ServerMetrics21sendLatencyTimepointsENSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEES4_RKSs, ServerMetrics,
              std::chrono::duration<long long, std::ratio<1ll, 1000000000ll>> dur1,
              std::chrono::duration<long long, std::ratio<1ll, 1000000000ll>> dur2, mcpe::string const &xuid) {
  printf("delay: %lld\n", std::chrono::duration_cast<std::chrono::milliseconds>(dur1).count());
  return;
}

SInstanceHook(void, _ZN13ServerMetrics18sendServerTickTimeENSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEE, ServerMetrics,
              std::chrono::duration<long long, std::ratio<1ll, 1000000000ll>> tick) {
  printf("tick time: %lld\n", std::chrono::duration_cast<std::chrono::milliseconds>(tick).count());
  return;
}

static_assert(sizeof(std::function<void(mcpe::string const &)>) == 16);

} // namespace