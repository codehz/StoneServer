#include "../custom_command.hpp"
#include "common.h"

namespace ExtAPI {
using namespace interface;

static void registerCommandCallback(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Length() != 4) {
    iso->ThrowException(Exception::TypeError(STR(strformat("registerCommand requires 4 arguments(current: %d)", info.Length()))));
    return;
  }
  if (!info[0]->IsString() || !info[1]->IsString() || !info[2]->IsNumber() || !info[3]->IsArray()) {
    iso->ThrowException(Exception::TypeError(STR("registerCommand requires (string, string, number, array)")));
    return;
  }
  const auto command = fromJS<std::string>(iso, info[0]);
  const auto desc    = fromJS<std::string>(iso, info[1]);
  const auto lvl     = fromJS<int>(iso, info[2]);
  auto strArguments  = toJS<std::string>(iso, "arguments");
  auto strHandler    = toJS<std::string>(iso, "handler");
  auto strName       = toJS<std::string>(iso, "name");
  auto strType       = toJS<std::string>(iso, "type");
  auto strOptional   = toJS<std::string>(iso, "optional");
  auto definitions   = Local<Array>(info[3]);

  auto registerOverload = registerCustomCommand(command, desc, lvl);
  for (unsigned i = 0; i < definitions->Length(); i++) {
    const auto val = definitions->Get(i);
    if (!val->IsObject()) {
      iso->ThrowException(Exception::TypeError(STR("registerCommand definition requires object")));
      return;
    }
    auto obj = Local<Object>(val);
    if (!obj->Has(strArguments) || !obj->Has(strHandler)) {
      iso->ThrowException(
          Exception::TypeError(STR("registerCommand definition requires { arguments: array, handler: function, optional?: boolean }")));
      return;
    }
    auto srcArguments = obj->Get(strArguments);
    if (!srcArguments->IsArray()) {
      iso->ThrowException(Exception::TypeError(STR("registerCommand definition arguments requires array")));
      return;
    }
    auto arguments  = Local<Array>(srcArguments);
    auto srcHandler = obj->Get(strHandler);
    if (!srcHandler->IsFunction()) {
      iso->ThrowException(Exception::TypeError(STR("registerCommand definition handler requires function")));
      return;
    }
    MyCommandVTable mvt;
    auto argc = arguments->Length();
    for (unsigned i = 0; i < argc; i++) {
      auto srcArg = arguments->Get(i);
      if (!srcArg->IsObject()) {
        iso->ThrowException(Exception::TypeError(STR("registerCommand definition arguments requires object")));
        return;
      }
      auto arg = Local<Object>(srcArg);
      if (!arg->Has(strName) || !arg->Has(strType)) {
        iso->ThrowException(Exception::TypeError(STR("registerCommand definition arguments requires { name: string, type: string }")));
        return;
      }
      auto argName = arg->Get(strName);
      if (!argName->IsString()) {
        iso->ThrowException(Exception::TypeError(STR("registerCommand definition arguments name requires string")));
        return;
      }
      auto argType = arg->Get(strType);
      if (!argType->IsString()) {
        iso->ThrowException(Exception::TypeError(STR("registerCommand definition arguments type requires string")));
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
      } else {
        iso->ThrowException(Exception::TypeError(STR("registerCommand definition arguments type is unknown")));
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