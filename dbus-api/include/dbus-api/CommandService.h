#pragma once

#include "stdafx.h"

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

INTERFACE(CommandService) {
  Method<in<string>, in<string>, out<string>> execute;
  Method<in<string>, in<unsigned>, out<vector<structs::AutoCompleteOption>>> complete;

  CommandService()
      : INIT(execute)
      , INIT(complete) {}
};

} // namespace one::codehz::stone