#include "../operators.h"
#include "../patched.h"

#include <minecraft/NetworkIdentifier.h>
#include <minecraft/TextPacket.h>
#include <stone/server_hook.h>

#include <interface/chat.h>
#include <interface/locator.hpp>
#include <interface/player_list.h>

namespace {

SHook(void, _ZN20ServerNetworkHandler10handleTextERK17NetworkIdentifierRK10TextPacket, void *handler, NetworkIdentifier const &id,
      TextPacket const &packet) {
  using namespace interface;
  auto &chat = Locator<Chat>();
  chat->onPlayerChat(id >> FindPlayerByNetworkID, packet.message >> StdStr);
  if (!chat->intercept) original(handler, id, packet);
}

static patched::details::RegisterPatchInit pinit([] {
  using namespace interface;
  Locator<Chat>().generate<>();
});

} // namespace