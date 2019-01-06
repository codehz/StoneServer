#pragma once

#include "stdafx.h"

namespace one::codehz::stone {
using namespace std;
using namespace simppl::dbus;

INTERFACE(BlacklistService) {
  Method<in<string>, in<string>, oneway> addByUUID;
  Method<in<string>, in<string>, oneway> addByXUID;
  Method<in<string>, in<string>> addByName;
  Method<in<string>, in<string>> kickByUUID;
  Method<in<string>, in<string>> kickByXUID;
  Method<in<string>, in<string>> kickByName;
  Method<in<string>, oneway> removeByUUID;
  Method<in<string>, oneway> removeByXUID;

  BlacklistService()
      : INIT(addByUUID)
      , INIT(addByXUID)
      , INIT(addByName)
      , INIT(kickByUUID)
      , INIT(kickByXUID)
      , INIT(kickByName)
      , INIT(removeByUUID)
      , INIT(removeByXUID) {}
};

} // namespace one::codehz::stone
