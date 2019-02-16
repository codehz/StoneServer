#include "common.h"
#include <sqlite3.h>
#include <stone/utils.h>

namespace WebAPI {

static void bind_sqlite3_open(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (!info.IsConstructCall()) {
    iso->ThrowException(Exception::TypeError(STR("Use the new operator to create new Database objects")));
  } else if (!info[0]->IsString()) {
    iso->ThrowException(Exception::TypeError(STR("Use new SQLite3(path: string)")));
  } else {
    auto dbname = info[0]->ToString(iso) >> V8Str;
    sqlite3 *db;
    if (sqlite3_open(dbname.c_str(), &db) != SQLITE_OK) {
      iso->ThrowException(STR("cannot open the database"));
    } else {
      info.Holder()->SetAlignedPointerInInternalField(0, db);
      info.Holder()->SetInternalField(1, v8::True(iso));
      info.GetReturnValue().Set(info.Holder());
    }
  }
}

static void bind_sqlite3_valid(FunctionCallbackInfo<Value> const &info) { info.GetReturnValue().Set(info.Holder()->GetInternalField(1)); }

static void bind_sqlite3_close(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Holder()->GetInternalField(1)->IsTrue()) {
    auto db = (sqlite3 *)info.Holder()->GetAlignedPointerFromInternalField(0);
    sqlite3_close(db);
    info.Holder()->SetInternalField(1, v8::False(iso));
  }
}

static void bind_sqlite3_exec(FunctionCallbackInfo<Value> const &info) {
  auto iso = info.GetIsolate();
  Isolate::Scope isos{ iso };
  if (info.Holder()->GetInternalField(1)->IsTrue()) {
    auto db      = (sqlite3 *)info.Holder()->GetAlignedPointerFromInternalField(0);
    char *errmsg = nullptr;
    if (info.Length() == 1 && info[0]->IsString()) {
      auto ret = sqlite3_exec(db, info[0] >> V8Str >> CStr, nullptr, nullptr, &errmsg);
      if (errmsg) iso->ThrowException(Exception::Error(STR(errmsg)));
      info.GetReturnValue().Set(v8::Integer::New(iso, ret));
    } else if (info.Length() == 2 && info[0]->IsString() && info[1]->IsFunction()) {
      TryCatch tc{ iso };
      auto tuple = std::tuple{ iso, Function::Cast(info[1]), &tc };
      auto ret   = sqlite3_exec(db, info[0] >> V8Str >> CStr,
                              +[](void *data, int num, char **keys, char **values) -> int {
                                auto &[iso, fn, tc] = *(decltype(tuple) *)data;
                                auto arg            = Object::New(iso);
                                for (int i = 0; i < num; i++) arg->Set(STR(keys[i]), STR(values[i]));
                                fn->Call(v8::Undefined(iso), 1, (Local<Value> *)&arg);
                                return tc->HasCaught();
                              },
                              &tuple, &errmsg);
      if (tc.HasCaught())
        tc.ReThrow();
      else if (errmsg)
        iso->ThrowException(Exception::Error(STR(errmsg)));
      else
        info.GetReturnValue().Set(v8::Integer::New(iso, ret));
    } else {
      iso->ThrowException(Exception::TypeError(STR("Use exec(sql: string, callback?: (line: { [index: string]: string }))")));
    }
    if (errmsg) sqlite3_free(errmsg);
  } else {
    iso->ThrowException(Exception::Error(STR("Database is closed")));
  }
}

#define copy_const(name) tmp_Database->Set(STR(#name), v8::Integer::New(iso, name))

Register reg([](Local<Object> &obj, Isolate *iso, Local<Context> &ctx) {
  auto tmp_Database = FunctionTemplate::New(iso, bind_sqlite3_open, 1);
  tmp_Database->SetClassName(STR("SQLite3"));
  {
    copy_const(SQLITE_OK);
    copy_const(SQLITE_ERROR);
    copy_const(SQLITE_INTERNAL);
    copy_const(SQLITE_PERM);
    copy_const(SQLITE_ABORT);
    copy_const(SQLITE_BUSY);
    copy_const(SQLITE_LOCKED);
    copy_const(SQLITE_NOMEM);
    copy_const(SQLITE_READONLY);
    copy_const(SQLITE_INTERRUPT);
    copy_const(SQLITE_IOERR);
    copy_const(SQLITE_CORRUPT);
    copy_const(SQLITE_NOTFOUND);
    copy_const(SQLITE_FULL);
    copy_const(SQLITE_CANTOPEN);
    copy_const(SQLITE_PROTOCOL);
    copy_const(SQLITE_EMPTY);
    copy_const(SQLITE_SCHEMA);
    copy_const(SQLITE_TOOBIG);
    copy_const(SQLITE_CONSTRAINT);
    copy_const(SQLITE_MISMATCH);
    copy_const(SQLITE_MISUSE);
    copy_const(SQLITE_NOLFS);
    copy_const(SQLITE_AUTH);
    copy_const(SQLITE_FORMAT);
    copy_const(SQLITE_RANGE);
    copy_const(SQLITE_NOTADB);
    copy_const(SQLITE_NOTICE);
    copy_const(SQLITE_WARNING);
    copy_const(SQLITE_ROW);
    copy_const(SQLITE_DONE);
  }
  auto proto_Database = tmp_Database->InstanceTemplate();
  proto_Database->SetInternalFieldCount(2);
  proto_Database->SetAccessorProperty(STR("valid"), FunctionTemplate::New(iso, bind_sqlite3_valid));
  proto_Database->Set(STR("close"), FunctionTemplate::New(iso, bind_sqlite3_close));
  proto_Database->Set(STR("exec"), FunctionTemplate::New(iso, bind_sqlite3_exec));
  obj->Set(STR("SQLite3"), tmp_Database->GetFunction(ctx));
});

} // namespace WebAPI