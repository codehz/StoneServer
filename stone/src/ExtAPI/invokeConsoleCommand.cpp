#include "common.h"
#include <interface/chat.h>
#include <minecraft/ServerCommandOrigin.h>
#include <minecraft/Level.h>
#include <minecraft/MinecraftCommands.h>

#include "../custom_command.h"

namespace ExtAPI {
using namespace interface;

static void invokeConsoleCommandCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 2) {
    iso->ThrowException(Exception::TypeError(STR(strformat("invokeConsoleCommand requires 2 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsString() || !info[1]->IsString()) {
    iso->ThrowException(Exception::TypeError(STR("invokeConsoleCommand requires (string, string)")));
    return;
  }
  auto orig    = fromJS<std::string>(iso, info[0]);
  auto command = fromJS<std::string>(iso, info[1]);
  auto result  = patched::withCommandOutput([&] {
    auto commandOrigin = std::make_unique<ServerCommandOrigin>(orig, *Locator<Level>());
    Locator<MinecraftCommands>()->requestCommandExecution(std::move(commandOrigin), command, 4, true);
  });
  info.GetReturnValue().Set(toJS(iso, result));
}

static Register reg{ "registerComponent", "invokeConsoleCommand", &invokeConsoleCommandCallback };

} // namespace ExtAPI