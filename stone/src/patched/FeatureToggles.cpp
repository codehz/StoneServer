#include "../patched.h"

#include <stone/server_hook.h>

namespace {

SClasslessInstanceHook(bool, _ZNK14FeatureToggles9isEnabledE15FeatureOptionID, int id) {
  return true;
}

} // namespace