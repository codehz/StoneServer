#pragma once

#include "stdafx.h"

namespace one::codehz::stone {
using namespace std;
using namespace simppl::dbus;

INTERFACE(ChatService) {
  Method<in<string>, in<string>, oneway> Send;
  Method<in<string>, oneway> Broadcast;
  Signal<string, string> Receive;
  Property<bool> Intercept;

  ChatService()
      : INIT(Send)
      , INIT(Broadcast)
      , INIT(Receive)
      , INIT(Intercept) {}
};

} // namespace one::codehz::stone
