#include "../patched.h"

#include <stone/server_hook.h>

namespace {

struct Option {
  char filler[0x14];
  mcpe::string name;
};

SClasslessInstanceHook(bool, _ZNK14FeatureToggles9isEnabledE15FeatureOptionID, int id) {
  static bool notified[256] = { 0 };
  if (notified[id]) return true;
  Option *ptr = *(Option **)((int)this + id * 4);
  Log::info("FeatureToggles", "Feature (%s): %d\n", ptr->name.c_str(), id);
  notified[id] = true;
  return true;
}

} // namespace