#pragma once

#include "stdafx.h"

namespace one::codehz::stone {
using namespace std;
using namespace simppl::dbus;

INTERFACE(ChatService) {
  Method<in<string>, in<string>, oneway> send;
  Method<in<string>, oneway> broadcast;
  Signal<string, string> recv;
  Property<bool> intercept;

  ChatService()
      : INIT(send)
      , INIT(broadcast)
      , INIT(recv)
      , INIT(intercept) {}
};

} // namespace one::codehz::stone
