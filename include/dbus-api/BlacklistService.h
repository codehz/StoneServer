#pragma once

#include "stdafx.h"

namespace one::codehz::stone {
using namespace std;
using namespace simppl::dbus;

INTERFACE(BlacklistService) {
  Method<in<string>, in<string>, oneway> addByUUID;
  Method<in<string>, in<string>, oneway> addByXUID;
  Method<in<string>, oneway> removeByUUID;
  Method<in<string>, oneway> removeByXUID;

  BlacklistService()
      : INIT(addByUUID)
      , INIT(addByXUID)
      , INIT(removeByUUID)
      , INIT(removeByXUID) {}
};

} // namespace one::codehz::stone
