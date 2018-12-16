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

SHook(TextPacket, _ZN10TextPacket10createChatERKSsS1_S1_S1_, mcpe::string const &orig, mcpe::string const &content, mcpe::string const &uuid,
      mcpe::string const &unk) {
  using namespace interface;
  if (unk == *mcpe::string::empty) {
    auto &chat = Locator<Chat>();
    chat->onChat(orig >> StdStr, content >> StdStr);
  }
  return original(orig, content, uuid, unk);
}

static patched::details::RegisterPatchInit pinit([] {
  using namespace interface;
  Locator<Chat>().generate<>();
});

} // namespace