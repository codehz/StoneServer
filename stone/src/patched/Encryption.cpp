#include "../dumper.h"
#include "../patched.h"

#include <stone/hook_helper.h>
#include <stone/server_hook.h>

#include <minecraft/Packet.h>
#include <minecraft/ServerNetworkHandler.h>

namespace {

SClasslessInstanceHook(void, _ZN20EncryptedNetworkPeer16enableEncryptionERKSs) {}
SInstanceHook(void, _ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK11LoginPacket, ServerNetworkHandler, NetworkIdentifier const &netId,
              void *packet) {
  original(this, netId, packet);
  ClientToServerHandshakePacket *whateverhonestly = nullptr;
  this->handle(netId, *whateverhonestly);
}

static patched::details::RegisterPatchInit pinit([] {
  BUILD_HELPER(DirectPatch, uint16_t, 0x12C5, "_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK11LoginPacket").VerifiedPatch(0xD1FF, 0x9090);
});

// !! Safe but slow
// SClasslessInstanceHook(void, _ZN20LoopbackPacketSender12sendToClientERK17NetworkIdentifierRK6Packeth, NetworkIdentifier const &netId, Packet
// *packet,
//                        unsigned char ch) {
//   if (packet->vtable != Packet::vt_serverToClientHandshake + 2) original(this, netId, packet, ch);
//   else dump_backtrace();
// }

} // namespace