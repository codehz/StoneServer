#include "common.h"
#include <interface/modal_form.h>
#include <interface/player_list.h>
#include <map>
#include <minecraft/ModalForm.h>

#include "../patched/ScriptInterface.h"

static_assert(sizeof(int) == sizeof(void *), "Only works in 32bit");

namespace ExtAPI {
using namespace interface;

struct ReqTicket {
  AutoReleasePersistent<Promise::Resolver> resolver;
  ReqTicket(AutoReleasePersistent<Promise::Resolver> &&resolver)
      : resolver(std::move(resolver)) {}
  ReqTicket(ReqTicket &&ticket)
      : resolver(std::move(ticket.resolver)) {}
  unsigned get_id() { return (unsigned)resolver.RawPointer(); }
  void resolve(std::string const &data) {
    auto &core = Locator<ScriptApi::V8CoreInterface>();
    auto iso   = patched::V8Isolate[*core];
    HandleScope scope{ iso };
    Isolate::Scope isos{ iso };
    auto ctx = patched::V8Context[*core].Get(iso);
    Context::Scope ctx_scope{ ctx };
    resolver.Get(iso)->Resolve(ctx, toJS(iso, data));
  }
  void reject(std::string const &data) {
    auto &core = Locator<ScriptApi::V8CoreInterface>();
    auto iso   = patched::V8Isolate[*core];
    HandleScope scope{ iso };
    Isolate::Scope isos{ iso };
    auto ctx = patched::V8Context[*core].Get(iso);
    Context::Scope ctx_scope{ ctx };
    resolver.Get(iso)->Reject(ctx, toJS(iso, data));
  }
  ~ReqTicket() {
    if (resolver) reject("Canceled");
  }
};

static std::map<Player *, ReqTicket> reqCache;

static void openModalFormCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  auto &core = Locator<ScriptApi::V8CoreInterface>();
  auto ctx   = patched::V8Context[*core].Get(iso);
  if (info.Length() != 2) {
    iso->ThrowException(Exception::TypeError(STR(strformat("openModalForm requires 2 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsObject() || !info[1]->IsString()) {
    iso->ThrowException(Exception::TypeError(STR("openModalForm requires (player, string)")));
    return;
  }
  auto actor = fromJS<Actor *>(iso, info[0]);
  auto data  = fromJS<std::string>(iso, info[1]);
  if (!actor || *(void **)actor != BUILD_HELPER(GetAddress, void, 0x8, "_ZTV12ServerPlayer").Address()) {
    iso->ThrowException(Exception::TypeError(STR("openModalForm requires (player, string)")));
    return;
  }
  auto player   = (Player *)actor;
  auto resolver = Promise::Resolver::New(ctx);
  AutoReleasePersistent pres{ iso, resolver };
  auto id          = (unsigned)pres.RawPointer();
  reqCache.emplace(player, ReqTicket{ std::move(pres) });
  info.GetReturnValue().Set(resolver->GetPromise());
  Locator<ModalForm>()->send(player, id, data);
}

static Register reg{ "registerComponent", "openModalForm", &openModalFormCallback, +[](Isolate *iso, Local<Context> &ctx) {
                      Locator<PlayerList>()->onPlayerRemoved >> [](Player &player) { reqCache.erase(&player); };
                      // Locator<ModalForm>()->recv >> [](unsigned id, Player *player, std::string const &data) {
                      //   printf("id: %d player: %p, data: %s\n", id, player, data.c_str());
                      // };
                      Locator<ModalForm>()->recv >> [](unsigned id, Player *player, std::string const &data) {
                        auto req_it = reqCache.find(player);
                        if (req_it == reqCache.end()) return;
                        if (req_it->second.get_id() != id) {
                          req_it->second.reject("Wrong response");
                        } else {
                          req_it->second.resolve(data);
                        }
                        reqCache.erase(req_it);
                      };
                    } };

} // namespace ExtAPI