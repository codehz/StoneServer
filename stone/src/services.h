#pragma once

#include <simppl/interface.h>
#include <simppl/struct.h>
#include <string>
#include <vector>

namespace one::codehz::stone {
using namespace std;
using namespace simppl::dbus;

namespace structs {
struct AutoCompleteOption {
  using serializer_type = make_serializer<string, string, string, int, int, int>::type;
  string source, title, desc;
  int offset, eat, item;
};
} // namespace structs

INTERFACE(CoreService) {
  Method<oneway> stop;
  Signal<int, string, string> log;

  CoreService()
      : INIT(stop)
      , INIT(log) {}
};

INTERFACE(CommandService) {
  Method<in<string>, in<string>, out<string>> execute;
  Method<in<string>, in<unsigned>, out<vector<structs::AutoCompleteOption>>> complete;

  CommandService()
      : INIT(execute)
      , INIT(complete) {}
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