#include "../custom_command.hpp"
#include "common.h"

namespace ExtAPI {
using namespace interface;

static void registerCommandCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 2) {
    iso->ThrowException(Exception::TypeError(ToJS(strformat("registerCommand requires 2 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsString() || !info[1]->IsObject()) {
    iso->ThrowException(Exception::TypeError(ToJS("registerCommand requires (string, object)")));
    return;
  }
  const auto command    = fromJS<std::string>(iso, info[0]);
  const auto definition = Local<Object>(info[1]);
  auto strDescription   = toJS<std::string>(iso, "description");
  auto strPermission    = toJS<std::string>(iso, "permission");
  auto strOverloads     = toJS<std::string>(iso, "overloads");
  auto strParameters    = toJS<std::string>(iso, "parameters");
  auto strHandler       = toJS<std::string>(iso, "handler");
  auto strName          = toJS<std::string>(iso, "name");
  auto strEnum          = toJS<std::string>(iso, "enum");
  auto strType          = toJS<std::string>(iso, "type");
  auto strOptional      = toJS<std::string>(iso, "optional");
  std::string desc;
  int level = 0;
  Local<Array> definitions;

  if (!definition->Has(strDescription) || !definition->Get(strDescription)->IsString()) {
    iso->ThrowException(Exception::TypeError(ToJS("registerCommand definition require description field")));
    return;
  }
  desc = definition->Get(strDescription) >> V8Str >> StdStr;
  if (definition->Has(strPermission) && definition->Get(strPermission)->IsNumber()) level = Local<Number>(definition->Get(strPermission))->Value();

  if (!definition->Has(strOverloads) || !definition->Get(strOverloads)->IsArray()) {
    iso->ThrowException(Exception::TypeError(ToJS("registerCommand definition require overloads field")));
    return;
  }
  definitions = Local<Array>(definition->Get(strOverloads));

  auto registerOverload = registerCustomCommand(command, desc, level);
  for (unsigned i = 0; i < definitions->Length(); i++) {
    const auto val = definitions->Get(i);
    if (!val->IsObject()) {
      iso->ThrowException(Exception::TypeError(ToJS("registerCommand definition requires object")));
      return;
    }
    auto obj = Local<Object>(val);
    if (!obj->Has(strParameters) || !obj->Has(strHandler)) {
      iso->ThrowException(
          Exception::TypeError(ToJS("registerCommand definition requires { parameters: array, handler: function, optional?: boolean }")));
      return;
    }
    auto srcParameters = obj->Get(strParameters);
    if (!srcParameters->IsArray()) {
      iso->ThrowException(Exception::TypeError(ToJS("registerCommand definition parameters requires array")));
      return;
    }
    auto parameters = Local<Array>(srcParameters);
    auto srcHandler = obj->Get(strHandler);
    if (!srcHandler->IsFunction()) {
      iso->ThrowException(Exception::TypeError(ToJS("registerCommand definition handler requires function")));
      return;
    }
    MyCommandVTable mvt;
    auto argc = parameters->Length();
    for (unsigned i = 0; i < argc; i++) {
      auto srcArg = parameters->Get(i);
      if (!srcArg->IsObject()) {
        iso->ThrowException(Exception::TypeError(ToJS("registerCommand definition parameter requires object")));
        return;
      }
      auto arg = Local<Object>(srcArg);
      if (!arg->Has(strName) || !arg->Has(strType)) {
        iso->ThrowException(Exception::TypeError(ToJS("registerCommand definition parameter requires { name: string, type: string }")));
        return;
      }
      auto argName = arg->Get(strName);
      if (!argName->IsString()) {
        iso->ThrowException(Exception::TypeError(ToJS("registerCommand definition parameter name requires string")));
        return;
      }
      auto argType = arg->Get(strType);
      if (!argType->IsString()) {
        iso->ThrowException(Exception::TypeError(ToJS("registerCommand definition parameter type requires string")));
        return;
      }
      auto theName = fromJS<std::string>(iso, argName);
      auto theType = fromJS<std::string>(iso, argType);
      if (theType == "message") {
        mvt.defs.push_back(messageParameter(theName));
      } else if (theType == "string") {
        mvt.defs.push_back(commonParameter<mcpe::string>(theName));
      } else if (theType == "int") {
        mvt.defs.push_back(commonParameter<int>(theName));
      } else if (theType == "float") {
        mvt.defs.push_back(commonParameter<float>(theName));
      } else if (theType == "bool") {
        mvt.defs.push_back(commonParameter<bool>(theName));
      } else if (theType == "text") {
        mvt.defs.push_back(commonParameter<CommandRawText>(theName));
      } else if (theType == "position") {
        mvt.defs.push_back(commonParameter<CommandPosition>(theName));
      } else if (theType == "selector") {
        mvt.defs.push_back(commonParameter<CommandSelector<Actor>>(theName));
      } else if (theType == "player-selector") {
        mvt.defs.push_back(commonParameter<CommandSelector<Player>>(theName));
      } else if (theType == "block") {
        mvt.defs.push_back(commonParameter<Block *>(theName));
      } else if (theType == "soft-enum") {
        if (!arg->Has(strEnum) || !arg->Get(strEnum)->IsString()) {
          iso->ThrowException(Exception::TypeError(ToJS("enum name is required")));
          return;
        }
        mvt.defs.push_back(enumParameter(theName, arg->Get(strEnum) >> V8Str >> StdStr));
      } else {
        iso->ThrowException(Exception::TypeError(ToJS("registerCommand definition parameter type is unknown")));
        return;
      }
      auto optional = arg->Get(strOptional)->BooleanValue();
      if (optional) mvt.defs.rbegin()->makeOptional();
    }
    mvt.iso  = iso;
    mvt.exec = [self = Persistent<Value>(iso, info.This()), handler = Persistent<Function>(iso, Local<Function>(srcHandler))](
                   Isolate *iso, int argc, v8::Local<v8::Value> *argv) -> v8::MaybeLocal<v8::Value> {
      auto origin = self.Get(iso);
      auto func   = handler.Get(iso);
      return func->Call(origin, argc, argv);
    };
    registerOverload(mvt);
  }
}

static Register reg{ "registerComponent", "registerCommand", &registerCommandCallback };

} // namespace ExtAPI