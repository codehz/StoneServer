#include "../operators.h"
#include "../patched.h"

#include <minecraft/NetworkIdentifier.h>
#include <minecraft/TextPacket.h>
#include <stone/server_hook.h>

#include <interface/chat.h>
#include <interface/locator.hpp>
#include <interface/player_list.h>

namespace {
using namespace interface;

SHook(void, _ZN20ServerNetworkHandler10handleTextERK17NetworkIdentifierRK10TextPacket, void *handler, NetworkIdentifier const &id,
      TextPacket const &packet) {
  using namespace interface;
  auto &chat = Locator<Chat>();
  chat->onPlayerChat(id >> FindPlayerByNetworkID, packet.message >> StdStr);
  if (!chat->intercept) original(handler, id, packet);
}

struct ChatImpl : Chat {
  void sendChat(std::string const &sender, std::string const &content) override {
    TextPacket text = TextPacket::createTranslatedAnnouncement(sender, mcpe::string("[") + sender + "] " + content, "", "1");
    Locator<Chat>()->onChat(sender, content);
    for (auto pplayer : Locator<PlayerList>()->set) {
      auto &player = *pplayer;
      if (player.canUseAbility("mute")) continue;
      player.sendNetworkPacket(text);
    }
  }
  void sendAnnouncement(std::string const &content) override {
    TextPacket text = TextPacket::createTranslatedAnnouncement("", content, "", "1");
    for (auto pplayer : Locator<PlayerList>()->set) {
      auto &player = *pplayer;
      player.sendNetworkPacket(text);
    }
  }
};

static patched::details::RegisterPatchInit pinit([] { Locator<Chat>() = new ChatImpl(); });

} // namespace