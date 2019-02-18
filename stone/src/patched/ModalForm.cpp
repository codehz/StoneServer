#include "../patched.h"

#include <interface/locator.hpp>
#include <interface/modal_form.h>
#include <interface/player_list.h>
#include <stone/server_hook.h>

#include <minecraft/ModalForm.h>
#include <minecraft/NetworkIdentifier.h>

#include "ScriptInterface.h"
#include "HardcodedOffsets.h"

#include <time.h>

namespace {
using namespace patched;
using namespace interface;

struct ModalFormImpl : interface::ModalForm {
  void send(Player *player, unsigned id, std::string const &content) {
    ModalFormRequestPacket packet{ id, content };
    player->sendNetworkPacket(packet);
  }
};

SHook(void, _ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK23ModalFormResponsePacket, void *, NetworkIdentifier const &id,
      ModalFormResponsePacket const &packet) {
  for (auto player : Locator<PlayerList>()->set) {
    if (PlayerNetworkID[*player] == id) {
      auto content = packet.content.std();
      Locator<interface::ModalForm>()->recv(packet.request_id, player, content);
      return;
    }
  }
}

static patched::details::RegisterPatchInit pinit([] { Locator<interface::ModalForm>() = new ModalFormImpl(); });

} // namespace