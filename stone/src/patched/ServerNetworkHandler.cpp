#include "../dumper.h"
#include "../patched.h"

#include "HardcodedOffsets.h"

#include <minecraft/ServerNetworkHandler.h>

#include <stone/hook_helper.h>
#include <stone/server_hook.h>

#include <climits>

#include <interface/blacklist.h>
#include <interface/locator.hpp>

namespace {
using namespace interface;
using namespace std::literals;
using namespace patched;

SInstanceHook(void, _ZN20ServerNetworkHandler24allowIncomingConnectionsERKSsb, ServerNetworkHandler, mcpe::string const &str, bool flag) {
  Locator<ServerNetworkHandler>() = this;
  original(this, str, flag);
}

SInstanceHook(bool, _ZNK9Blacklist13isUUIDBlockedERKN3mce4UUIDERN9__gnu_cxx17__normal_iteratorIPKNS_5EntryESt6vectorIS6_SaIS6_EEEE, ::Blacklist,
              mce::UUID const &uuid, void *iter) {
  if (uuid.isEmpty()) return false;
  return original(this, uuid, iter);
}

SInstanceHook(bool, _ZNK9Blacklist13isXUIDBlockedERKSsRN9__gnu_cxx17__normal_iteratorIPKNS_5EntryESt6vectorIS4_SaIS4_EEEE, ::Blacklist,
              mcpe::string const &xuid, void *iter) {
  if (xuid.length() == 0) return false;
  return original(this, xuid, iter);
}

SInstanceHook(void, _ZN9Blacklist11removeEntryERKNS_5EntryE, ::Blacklist, ::Blacklist::Entry const &entry) {
  if (entry.name.length() == 0)
    this->vec.erase(std::remove_if(this->vec.begin(), this->vec.end(), [&](auto &rhs) { return rhs.uuid == entry.uuid; }), this->vec.end());
  else
    this->vec.erase(std::remove_if(this->vec.begin(), this->vec.end(), [&](auto &rhs) { return rhs.name.std() == entry.name.std(); }),
                    this->vec.end());
}

class BlacklistImpl : public interface::Blacklist {
  void add(mce::UUID const &uuid, std::string const &reason) override { Locator<ServerNetworkHandler>()->addToBlacklist(uuid, "", reason, 0); }
  void add(std::string const &xuid, std::string const &reason) override {
    Locator<ServerNetworkHandler>()->addToBlacklist(*mce::UUID::EMPTY, xuid, reason, INT_MAX);
  }
  void remove(mce::UUID const &uuid) override { Locator<ServerNetworkHandler>()->removeFromBlacklist(uuid, ""); }
  void remove(std::string const &xuid) override { Locator<ServerNetworkHandler>()->removeFromBlacklist(*mce::UUID::EMPTY, xuid); }
  void kick(NetworkIdentifier const &id, std::string const &reason) override { Locator<ServerNetworkHandler>()->disconnectClient(id, reason, true); }
  void forEach(std::function<void(std::variant<mce::UUID, std::string> const &, std::string const &)> const &fn) override {
    auto &bl = BlacklistFromNetworkHandler[*Locator<ServerNetworkHandler>()];
    for (auto &entry : bl.vec) {
      if (entry.name.length())
        fn(entry.name.std(), entry.reason.std());
      else
        fn(entry.uuid, entry.reason.std());
    }
  }
};

struct __attribute__((__packed__)) jump {
  char jz_jnz = 0x74;
  char offset;
  bool operator==(jump const &rhs) { return jz_jnz == rhs.jz_jnz && offset == rhs.offset; }
  [[maybe_unused]] friend std::ostream &operator<<(std::ostream &out, jump const &self) {
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
  Locator<interface::Blacklist>() = new BlacklistImpl();
  BUILD_HELPER(DirectPatch, jump, 0x21, "_ZN9Blacklist8addEntryERKNS_5EntryE").VerifiedPatch(jump{ 0x74, 0x10 }, jump{ 0x75, 0x10 });
  BUILD_HELPER(DirectPatch, jump, 0xD2, "_ZN9Blacklist8addEntryERKNS_5EntryE").VerifiedPatch(jump{ 0x75, 0x17 }, jump{ 0x74, 0x17 });
  BUILD_HELPER(DirectPatch, jump, 0xE9, "_ZN9Blacklist8addEntryERKNS_5EntryE").VerifiedPatch(jump{ 0x74, 0x0C }, jump{ 0x75, 0x0C });
});

} // namespace