#pragma once

#include "stdafx.h"

namespace one::codehz::stone {
using namespace std;
using namespace simppl::dbus;

INTERFACE(ChatService) {
  Method<in<string>, in<string>, oneway> send;
  Signal<string, string> recv;
  Property<bool> intercept;

  ChatService()
      : INIT(send)
      , INIT(recv)
      , INIT(intercept) {}
};

} // namespace one::codehz::stone
