#pragma once

#include "stdafx.h"

namespace one::codehz::stone {
using namespace std;
using namespace simppl::dbus;

INTERFACE(BlacklistService) {
  Method<in<string>, in<string>, oneway> AddByUUID;
  Method<in<string>, in<string>, oneway> AddByXUID;
  Method<in<string>, in<string>> AddByName;
  Method<in<string>, in<string>> KickByUUID;
  Method<in<string>, in<string>> KickByXUID;
  Method<in<string>, in<string>> KickByName;
  Method<in<string>, oneway> RemoveByUUID;
  Method<in<string>, oneway> RemoveByXUID;

  BlacklistService()
      : INIT(AddByUUID)
      , INIT(AddByXUID)
      , INIT(AddByName)
      , INIT(KickByUUID)
      , INIT(KickByXUID)
      , INIT(KickByName)
      , INIT(RemoveByUUID)
      , INIT(RemoveByXUID) {}
};

} // namespace one::codehz::stone
