#include "../dumper.h"
#include "../patched.h"
#include <interface/locator.hpp>

#include <interface/locator.hpp>
#include <stone/server_hook.h>

#include "../server_properties.h"

namespace {
using namespace interface;

SHook(bool, _ZN16EducationOptions24isBaseCodeBuilderEnabledEv) { return true; }
SHook(bool, _ZN16EducationOptions18isChemistryEnabledEv) { return true; }
SHook(bool, _ZN16EducationOptions20isCodeBuilderEnabledEv) { return true; }
SHook(bool, _ZNK6Social4User11isConnectedEv) { return true; }
SHook(bool, _ZNK11AppPlatform9isEduModeEv) { return true; }

struct IsExperimentalDescription {
  void *vtable;
  bool isExperimental;
};

SInstanceHook(bool, _ZN25IsExperimentalDescription5parseERN4Json5ValueE, IsExperimentalDescription, void *json) {
  this->isExperimental = Locator<ServerProperties>()->experimentMode ? false : original(this, json);
  return true;
}

} // namespace