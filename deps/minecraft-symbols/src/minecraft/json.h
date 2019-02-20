#pragma once

#include "std/string.h"
#include <iostream>

namespace Json {

struct Value;

struct Reader {
  char filler[0x100];

  Reader();

  /// @symbol _ZN4Json6Reader5parseERSiRNS_5ValueEb
  bool parse(std::istream &is, Json::Value &root, bool collectComments);
};

struct StyledWriter {
  char filler[0x100];
  StyledWriter();
  ~StyledWriter();

  /// @symbol _ZN4Json12StyledWriter5writeERKNS_5ValueE
  mcpe::string write(Json::Value const &root);
};

struct FastWriter {
  char filler[0x100];
  FastWriter();
  ~FastWriter();

  /// @symbol _ZN4Json10FastWriter5writeERKNS_5ValueE
  mcpe::string write(Json::Value const &root);
};

enum ValueType {
  nullValue = 0, ///< 'null' value
  intValue,      ///< signed integer value
  uintValue,     ///< unsigned integer value
  realValue,     ///< double value
  stringValue,   ///< UTF-8 string value
  booleanValue,  ///< bool value
  arrayValue,    ///< array value (ordered list)
  objectValue    ///< object value (collection of name/value pairs).
};

struct Value {
  char filler[0x10];

  /// @symbol _ZN4Json5ValueC2ENS_9ValueTypeE
  Value(Json::ValueType);

  /// @symbol _ZN4Json5ValueD2Ev
  ~Value();
};

}