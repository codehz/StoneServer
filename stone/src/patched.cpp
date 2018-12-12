#include "patched.h"

namespace patched {

std::vector<void (*)()> init_fns;
std::vector<void (*)()> dest_fns;

namespace details {
RegisterPatchInit::RegisterPatchInit(void (*fn)(), void (*dest_fn)()) {
  if (fn) init_fns.push_back(fn);
  if (dest_fn) dest_fns.push_back(dest_fn);
}
} // namespace details

void init() {
  for (auto fn : init_fns) fn();
}

void dest() {
  for (auto fn : dest_fns) fn();
}

} // namespace patched