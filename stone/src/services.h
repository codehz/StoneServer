#pragma once

#include <simppl/interface.h>
#include <string>

namespace one::codehz::stone {
using namespace std;
using namespace simppl::dbus;
INTERFACE(CoreService) {
  Method<> stop;

  CoreService()
      : INIT(stop) {}
};

INTERFACE(CommandService) {
  Method<in<string>, in<string>, out<string>> execute;

  CommandService()
      : INIT(execute) {}
};

INTERFACE(ChatService) {
  Method<in<string>, in<string>> send;
  Signal<string, string> recv;
  Property<bool> intercept;

  ChatService()
      : INIT(send)
      , INIT(recv)
      , INIT(intercept) {}
};

} // namespace one::codehz::stone