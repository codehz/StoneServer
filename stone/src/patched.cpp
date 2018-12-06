#include "patched.h"

namespace patched {

std::vector<void (*)()> fns;

namespace details {
RegisterPatchInit::RegisterPatchInit(void (*fn)()) { fns.push_back(fn); }
} // namespace details

void init() {
  for (auto fn : fns) fn();
}

} // namespace patched