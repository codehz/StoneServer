#include "../patched/Flags.h"
#include "common.h"
#include <interface/chat.h>
#include <minecraft/CommandOrigin.h>
#include <minecraft/MinecraftCommands.h>

namespace ExtAPI {
using namespace interface;

static void invokePrivilegedCommandCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 2) {
    iso->ThrowException(Exception::TypeError(STR(strformat("invokePrivilegedCommand requires 2 arguments(current: %d)", info.Length()))));
    return;
  }

  if (!info[0]->IsObject() || !info[1]->IsString()) {
    iso->ThrowException(Exception::TypeError(STR("invokePrivilegedCommand requires (object, string)")));
    return;
  }
  auto actor   = fromJS<Actor *>(iso, info[0]);
  auto command = fromJS<std::string>(iso, info[1]);
  if (!actor || *(void **)actor != BUILD_HELPER(GetAddress, void, 0x8, "_ZTV12ServerPlayer").Address()) {
    iso->ThrowException(Exception::TypeError(STR("invokePrivilegedCommand requires (player, string)")));
    return;
  }
  auto origin                       = std::make_unique<PlayerCommandOrigin>((Player &)*actor);
  patched::flags::CommandPrivileged = true;
  auto result = patched::withCommandOutput([&] { Locator<MinecraftCommands>()->requestCommandExecution(std::move(origin), command, 4, true); });
  patched::flags::CommandPrivileged = false;
  info.GetReturnValue().Set(toJS(iso, result));
}

static Register reg{ "registerComponent", "invokePrivilegedCommand", &invokePrivilegedCommandCallback };

} // namespace ExtAPI