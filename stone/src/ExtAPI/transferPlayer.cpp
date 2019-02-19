#include "common.h"
#include <interface/chat.h>
#include <minecraft/TransferPacket.h>

namespace ExtAPI {
using namespace interface;

static void transferPlayerCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 3) {
    iso->ThrowException(Exception::TypeError(ToJS(strformat("transferPlayer requires 3 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsObject() || !info[1]->IsString() || !info[2]->IsInt32()) {
    iso->ThrowException(Exception::TypeError(ToJS("transferPlayer requires (object, string, integer)")));
    return;
  }
  Actor *actor = fromJS<Actor *>(iso, info[0]);
  if (!actor || *(void **)actor != BUILD_HELPER(GetAddress, void, 0x8, "_ZTV12ServerPlayer").Address()) {
    iso->ThrowException(Exception::TypeError(ToJS("transferPlayer requires (player, string, integer)")));
    return;
  }
  Player *player = (Player *)actor;

  TransferPacket packet{ fromJS<std::string>(iso, info[1]), fromJS<short>(iso, info[2]) };
  player->sendNetworkPacket(packet);
}

static Register reg{ "registerComponent", "transferPlayer", &transferPlayerCallback };

} // namespace ExtAPI