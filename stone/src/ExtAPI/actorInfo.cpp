#include "../patched/HardcodedOffsets.h"
#include "common.h"

namespace ExtAPI {
using namespace patched;

static void actorInfoCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 1) {
    iso->ThrowException(Exception::TypeError(ToJS(strformat("actorInfo requires 1 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsObject()) {
    iso->ThrowException(Exception::TypeError(ToJS("actorInfo requires (object)")));
    return;
  }
  Actor *actor = fromJS<Actor *>(iso, info[0]);
  if (!actor) {
    iso->ThrowException(Exception::TypeError(ToJS("actorInfo requires (actor)")));
    return;
  }
  auto temp            = Object::New(iso);
  auto strName         = ToJS("name");
  auto strIdentifier   = ToJS("identifier");
  auto strVariant      = ToJS("variant");
  auto strAirSupply    = ToJS("airSupply");
  auto strStrength     = ToJS("strength");
  auto strPos          = ToJS("pos");
  auto strDim          = ToJS("dim");
  auto strRide         = ToJS("ride");
  auto strRideRoot     = ToJS("rideRoot");
  auto strTarget       = ToJS("target");
  auto strArmors       = ToJS("armors");
  auto strUUID         = ToJS("uuid");
  auto strXUID         = ToJS("xuid");
  auto strPermission   = ToJS("permission");
  auto strSpawnPoint   = ToJS("spawnPoint");
  auto strSelectedItem = ToJS("selectedItem");
  auto strSleepTimer   = ToJS("sleepTimer");
  auto strAttackDamage = ToJS("attackDamage");
  auto strAgent        = ToJS("agent");
  temp->Set(strName, ToJS(actor->getNameTag().std()));
  temp->Set(strIdentifier, ToJS(actor->getActorIdentifier().getFullName().std()));
  temp->Set(strVariant, ToJS(actor->getVariant()));
  temp->Set(strAirSupply, ToJS(std::make_tuple(actor->getAirSupply(), actor->getTotalAirSupply())));
  temp->Set(strStrength, ToJS(std::make_tuple(actor->getStrength(), actor->getStrengthMax())));
  temp->Set(strRide, ToJS(actor->getRide()));
  temp->Set(strRideRoot, ToJS(actor->getRideRoot()));
  temp->Set(strTarget, ToJS(actor->getTarget()));
  auto armors = Array::New(iso, 4);
  armors->Set(0, ToJS(&actor->getArmor((ArmorSlot)0)));
  armors->Set(1, ToJS(&actor->getArmor((ArmorSlot)1)));
  armors->Set(2, ToJS(&actor->getArmor((ArmorSlot)2)));
  armors->Set(3, ToJS(&actor->getArmor((ArmorSlot)3)));
  temp->Set(strArmors, ToJS(armors));
  temp->Set(strPos, ToJS(actor->getPos()));
  auto [did] = actor->getDimensionId();
  temp->Set(strDim, ToJS(did));
  if (*(void **)actor == BUILD_HELPER(GetAddress, void, 0x8, "_ZTV12ServerPlayer").Address()) {
    auto player = (Player *)actor;
    temp->Set(strUUID, ToJS((*player) >> PlayerUUID >> UUIDStr >> StdStr));
    temp->Set(strXUID, ToJS((*player) >> PlayerXUID >> StdStr));
    temp->Set(strPermission, ToJS(player->getCommandPermissionLevel()));
    temp->Set(strSpawnPoint, ToJS(player->getSpawnPosition()));
    temp->Set(strSelectedItem, ToJS(&player->getSelectedItem()));
    temp->Set(strSleepTimer, ToJS(player->getSleepTimer()));
    temp->Set(strAttackDamage, ToJS(player->getAttackDamage()));
    temp->Set(strAgent, ToJS(player->getAgent()));
  }
  info.GetReturnValue().Set(temp);
}

static Register reg{ "registerComponent", "actorInfo", &actorInfoCallback };

}; // namespace ExtAPI