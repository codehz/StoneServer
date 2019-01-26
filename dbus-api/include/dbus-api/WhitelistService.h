#pragma once

#include "stdafx.h"

namespace one::codehz::stone {
using namespace std;
using namespace simppl::dbus;

INTERFACE(WhitelistService) {
  Method<oneway> Reload;
  Method<oneway> Dump;

  WhitelistService()
      : INIT(Reload)
      , INIT(Dump) {}
};

} // namespace one::codehz::stone
