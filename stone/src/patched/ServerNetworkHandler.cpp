#include "../patched.h"

#include <minecraft/ServerNetworkHandler.h>

#include <stone/hook_helper.h>
#include <stone/server_hook.h>

#include <interface/blacklist.h>
#include <interface/locator.hpp>

namespace {
using namespace interface;
using namespace std::literals;

SInstanceHook(void, _ZN20ServerNetworkHandler24allowIncomingConnectionsERKSsb, ServerNetworkHandler, mcpe::string const &str, bool flag) {
  Locator<ServerNetworkHandler>() = this;
  original(this, str, flag);
}

class BlacklistImpl : public interface::Blacklist {
  void add(mce::UUID const &uuid, std::string const &reason) override { Locator<ServerNetworkHandler>()->addToBlacklist(uuid, "", reason, 100s); }
  void add(std::string const &xuid, std::string const &reason) override {
    Locator<ServerNetworkHandler>()->addToBlacklist(*mce::UUID::EMPTY, xuid, reason, 100s);
  }
  void remove(mce::UUID const &uuid) override { Locator<ServerNetworkHandler>()->removeFromBlacklist(uuid, ""); }
  void remove(std::string const &xuid) override { Locator<ServerNetworkHandler>()->removeFromBlacklist(*mce::UUID::EMPTY, xuid); }
  void kick(NetworkIdentifier const &id, std::string const &reason) override { Locator<ServerNetworkHandler>()->disconnectClient(id, reason, true); }
};

struct __attribute__((__packed__)) jump {
  char jz_jnz = 0x74;
  char offset;
  bool operator==(jump const &rhs) { return jz_jnz == rhs.jz_jnz && offset == rhs.offset; }
  friend std::ostream &operator<<(std::ostream &out, jump const &self) {
    switch (self.jz_jnz) {
    case 0x74: out << "jz  "; break;
    case 0x75: out << "jnz "; break;
    default: out << self.jz_jnz << " "; break;
    }
    return out << "0x" << (int)self.offset;
  }
};

static patched::details::RegisterPatchInit pinit([] {
  using namespace interface;
  Locator<Blacklist>() = new BlacklistImpl();
  BUILD_HELPER(DirectPatch, jump, 0x21, "_ZN9Blacklist8addEntryERKNS_5EntryE").VerifiedPatch(jump{ 0x74, 0x10 }, jump{ 0x75, 0x10 });
  BUILD_HELPER(DirectPatch, jump, 0xD2, "_ZN9Blacklist8addEntryERKNS_5EntryE").VerifiedPatch(jump{ 0x75, 0x17 }, jump{ 0x74, 0x17 });
  BUILD_HELPER(DirectPatch, jump, 0xE9, "_ZN9Blacklist8addEntryERKNS_5EntryE").VerifiedPatch(jump{ 0x74, 0x0C }, jump{ 0x75, 0x0C });
});

} // namespace