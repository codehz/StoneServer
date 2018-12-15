#include "../patched.h"

#include <minecraft/CommandMessage.h>
#include <minecraft/CommandOrigin.h>
#include <minecraft/CommandOutput.h>
#include <minecraft/I18n.h>
#include <minecraft/MessagingCommand.h>
#include <minecraft/Packet.h>
#include <minecraft/TextPacket.h>

#include <stone/server_hook.h>
#include <stone/utils.h>

#include <interface/locator.hpp>
#include <interface/player_list.h>

class SayCommand : public MessagingCommand {
public:
  CommandMessage message;
};

// class Packet

namespace {

SInstanceHook(void, _ZNK10SayCommand7executeERK13CommandOriginR13CommandOutput, SayCommand, CommandOrigin &orig, CommandOutput &output) {
  using namespace interface;
  if (!checkChatPermissions(orig, output)) return;
  auto sender  = I18n::get(orig.getName(), {});
  auto content = message.getMessage(orig);
  Log::info("Chat", "%s say: %s.", sender.c_str(), content.c_str());
  TextPacket text = TextPacket::createTranslatedAnnouncement(sender, mcpe::string("[") + sender + "] " + content, orig.getUUID().asString(), "1");
  for (auto pplayer : Locator<PlayerList>()->set) {
    auto &player = *pplayer;
    player.sendNetworkPacket(text);
  }
  output.success();
}

} // namespace