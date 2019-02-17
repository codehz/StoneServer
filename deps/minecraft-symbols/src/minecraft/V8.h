#pragma once

#include "V8Internals.h"
#include <cstdint>
#include <cstring>
#include <type_traits>

namespace v8 {

template <class T> class BaseLocal {
public:
  BaseLocal()
      : val_(nullptr) {}
  BaseLocal(T *val)
      : val_(val) {}
  bool IsEmpty() const { return val_ == nullptr; }
  void Clear() { val_ = nullptr; }
  T *operator->() const { return val_; }
  T *operator*() const { return val_; }
  operator T *() const { return val_; }

protected:
  T *val_;
};

template <class T> struct Local : BaseLocal<T> {
  Local()
      : BaseLocal<T>() {}
  Local(T *val)
      : BaseLocal<T>(val) {}
  template <typename F>
  Local(Local<F> rhs)
      : BaseLocal<T>(T::Cast(*rhs)) {}
};
template <class T> struct Maybe : BaseLocal<T> {
  Maybe()
      : BaseLocal<T>() {}
  Maybe(T *val)
      : BaseLocal<T>(val) {}
};
template <class T> struct MaybeLocal : BaseLocal<T> {
  MaybeLocal()
      : BaseLocal<T>() {}
  MaybeLocal(T *val)
      : BaseLocal<T>(val) {}
};

class Isolate;
class Platform;
class Value;
class Object;
class Array;
class Context;
class Boolean;
class Number;
class Name;
class String;
class Message;
class Integer;
class Int32;
class Uint32;
class Data;
class Template;
class FunctionTemplate;
class Signature;
using Primitive = Value;

struct V8 {
  static bool Initialize();
  /// @symbol _ZN2v82V818InitializePlatformEPNS_8PlatformE
  static void InitializePlatform(v8::Platform *platform);
  /// @symbol _ZN2v82V818GlobalizeReferenceEPNS_8internal7IsolateEPPNS1_6ObjectE
  static void *GlobalizeReference(v8::Isolate *iso, void *inp);
  /// @symbol _ZN2v811HandleScope12CreateHandleEPNS_8internal7IsolateEPNS1_6ObjectE
  static void *CreateHandle(v8::Isolate *, void *);
};

struct Task {
  /// @skipped
  virtual ~Task() = default;
  /// @skipped
  virtual void Run() = 0;
};
struct IdleTask {
  /// @skipped
  virtual ~IdleTask() = default;
  /// @skipped
  virtual void Run(double deadline_in_seconds) = 0;
};

enum ExpectedRuntime { kShortRunningTask, kLongRunningTask };

class Data {
public:
  template <typename T> inline static Data *Cast(T *input) { return static_cast<Data *>(input); }
};

class Value : public Data {
  bool FullIsNull() const;
  bool FullIsUndefined() const;
  bool FullIsString() const;

public:
  template <typename T> inline static Value *Cast(T *value) { return static_cast<Value *>(value); }
  inline bool IsNull() const { return FullIsNull(); };
  inline bool IsUndefined() const { return FullIsUndefined(); };
  inline bool IsNullOrUndefined() const { return FullIsNull() || FullIsUndefined(); };
  inline bool IsString() const { return FullIsString(); };

  bool IsTrue() const;
  bool IsFalse() const;
  bool IsName() const;
  bool IsSymbol() const;
  bool IsFunction() const;
  bool IsArray() const;
  bool IsObject() const;
  bool IsBoolean() const;
  bool IsNumber() const;
  bool IsExternal() const;
  bool IsInt32() const;
  bool IsUint32() const;
  bool IsDate() const;
  bool IsArgumentsObject() const;
  bool IsBooleanObject() const;
  bool IsNumberObject() const;
  bool IsStringObject() const;
  bool IsSymbolObject() const;
  bool IsNativeError() const;
  bool IsRegExp() const;
  bool IsAsyncFunction() const;
  bool IsGeneratorFunction() const;
  bool IsGeneratorObject() const;
  bool IsPromise() const;
  bool IsMap() const;
  bool IsSet() const;
  bool IsMapIterator() const;
  bool IsSetIterator() const;
  bool IsWeakMap() const;
  bool IsWeakSet() const;
  bool IsArrayBuffer() const;
  bool IsArrayBufferView() const;
  bool IsTypedArray() const;
  bool IsUint8Array() const;
  bool IsUint8ClampedArray() const;
  bool IsInt8Array() const;
  bool IsUint16Array() const;
  bool IsInt16Array() const;
  bool IsUint32Array() const;
  bool IsInt32Array() const;
  bool IsFloat32Array() const;
  bool IsFloat64Array() const;
  bool IsDataView() const;
  bool IsSharedArrayBuffer() const;
  bool IsProxy() const;
  bool IsWebAssemblyCompiledModule() const;

  /// @symbol _ZNK2v85Value9ToBooleanEPNS_7IsolateE
  v8::Local<v8::Boolean> ToBoolean(v8::Isolate *isolate) const;
  /// @symbol _ZNK2v85Value8ToNumberEPNS_7IsolateE
  v8::Local<v8::Number> ToNumber(v8::Isolate *isolate) const;
  /// @symbol _ZNK2v85Value8ToStringEPNS_7IsolateE
  v8::Local<v8::String> ToString(v8::Isolate *isolate) const;
  /// @symbol _ZNK2v85Value8ToObjectEPNS_7IsolateE
  v8::Local<v8::Object> ToObject(v8::Isolate *isolate) const;
  /// @symbol _ZNK2v85Value9ToIntegerEPNS_7IsolateE
  v8::Local<v8::Integer> ToInteger(v8::Isolate *isolate) const;
  /// @symbol _ZNK2v85Value7ToInt32EPNS_7IsolateE
  v8::Local<v8::Int32> ToInt32(v8::Isolate *isolate) const;

  bool BooleanValue() const;
  v8::MaybeLocal<v8::Uint32> ToArrayIndex() const;

  /// @symbol _ZNK2v85Value6EqualsENS_5LocalINS_7ContextEEENS1_IS0_EE
  v8::Maybe<bool> Equals(v8::Local<v8::Context> context, v8::Local<v8::Value> that) const;
  /// @symbol _ZNK2v85Value6EqualsENS_5LocalIS0_EE
  v8::Maybe<bool> Equals(v8::Local<v8::Value> that) const;
  /// @symbol _ZNK2v85Value12StrictEqualsENS_5LocalIS0_EE
  bool StrictEquals(v8::Local<v8::Value> that) const;
  /// @symbol _ZNK2v85Value9SameValueENS_5LocalIS0_EE
  bool SameValue(v8::Local<v8::Value> that) const;

  /// @symbol _ZN2v85Value6TypeOfEPNS_7IsolateE
  v8::Local<v8::String> TypeOf(v8::Isolate *);
};

class Name : public Value {
  /// @symbol _ZN2v84Name9CheckCastEPNS_5ValueE
  static void CheckCast(v8::Value *obj);

public:
  inline static Name *Cast(Value *obj) {
    CheckCast(obj);
    return (Name *)obj;
  }
};

enum NewStringType { kNormal, kInternalized };

class String : public Name {
  /// @symbol _ZN2v86String9CheckCastEPNS_5ValueE
  static void CheckCast(v8::Value *obj);

public:
  inline static String *Cast(Value *obj) {
    CheckCast(obj);
    return (String *)obj;
  }
  int Length() const;
  int Utf8Length() const;
  bool IsOneByte() const;
  bool ContainsOnlyOneByte() const;
  bool IsExternal() const;
  bool IsExternalOneByte() const;

  /// @symbol _ZN2v86String11NewFromUtf8EPNS_7IsolateEPKcNS_13NewStringTypeEi
  static v8::Local<v8::String> NewFromUtf8Impl(v8::Isolate *isolate, char const *data, v8::NewStringType type, int length);
  inline static v8::Local<v8::String> NewFromUtf8(v8::Isolate *isolate, char const *data, v8::NewStringType type = kNormal, int length = -1) { return NewFromUtf8Impl(isolate, data, type, length); }

  /// @symbol _ZN2v86String14NewFromTwoByteEPNS_7IsolateEPKtNS_13NewStringTypeEi
  static v8::Local<v8::String> NewFromTwoByteImpl(v8::Isolate *isolate, char16_t const *data, v8::NewStringType type, int length);
  inline static v8::Local<v8::String> NewFromTwoByte(v8::Isolate *isolate, char16_t const *data, v8::NewStringType type = kNormal, int length = -1) { return NewFromTwoByteImpl(isolate, data, type, length); }

  enum WriteOptions { NO_OPTIONS = 0, HINT_MANY_WRITES_EXPECTED = 1, NO_NULL_TERMINATION = 2, PRESERVE_ONE_BYTE_NULL = 4, REPLACE_INVALID_UTF8 = 8 };
  /// @symbol _ZNK2v86String5WriteEPtiii
  int WriteImpl(unsigned short *buffer, int start, int length, int options) const;
  inline int Write(unsigned short *buffer, int start = 0, int length = -1, int options = NO_OPTIONS) const { return WriteImpl(buffer, start, length, options); }

  class Utf8Value {
    char *str_;
    int length_;

  public:
    /// @symbol _ZN2v86String9Utf8ValueC2ENS_5LocalINS_5ValueEEE
    Utf8Value(v8::Isolate *isolate, v8::Local<v8::Value> obj);
    ~Utf8Value();
    inline char *operator*() { return str_; }
    inline const char *operator*() const { return str_; }
    inline int length() const { return length_; }

    /// @skipped
    Utf8Value(const Utf8Value &) = delete;
    /// @skipped
    void operator=(const Utf8Value &) = delete;
  };
};

class Number : public Value {
  /// @symbol _ZN2v86Number9CheckCastEPNS_5ValueE
  static void CheckCast(v8::Value *obj);

public:
  inline static Number *Cast(v8::Value *obj) {
    CheckCast(obj);
    return (Number *)obj;
  }
  /// @symbol _ZN2v86Number3NewEPNS_7IsolateEd
  static v8::Local<v8::Number> New(v8::Isolate *isolate, double value);
  double Value() const;
};

class Integer : public Number {
  /// @symbol _ZN2v87Integer9CheckCastEPNS_5ValueE
  static void CheckCast(v8::Value *obj);

public:
  inline static Integer *Cast(v8::Value *obj) {
    CheckCast(obj);
    return (Integer *)obj;
  }
  /// @symbol _ZN2v87Integer3NewEPNS_7IsolateEi
  static v8::Local<v8::Integer> New(v8::Isolate *isolate, int32_t value);
  /// @symbol _ZN2v87Integer15NewFromUnsignedEPNS_7IsolateEj
  static v8::Local<v8::Integer> NewFromUnsigned(v8::Isolate *isolate, uint32_t value);
  int64_t Value() const;
};

inline Local<Primitive> Undefined(Isolate *isolate) {
  using namespace internal;
  Address *slot = GetRoot(isolate, kUndefinedValueRootIndex);
  return Local<Primitive>(reinterpret_cast<Primitive *>(slot));
}

inline Local<Primitive> Null(Isolate *isolate) {
  using namespace internal;
  Address *slot = GetRoot(isolate, kNullValueRootIndex);
  return Local<Primitive>(reinterpret_cast<Primitive *>(slot));
}

inline Local<Boolean> True(Isolate *isolate) {
  using namespace internal;
  Address *slot = GetRoot(isolate, kTrueValueRootIndex);
  return Local<Boolean>(reinterpret_cast<Boolean *>(slot));
}

inline Local<Boolean> False(Isolate *isolate) {
  using namespace internal;
  Address *slot = GetRoot(isolate, kFalseValueRootIndex);
  return Local<Boolean>(reinterpret_cast<Boolean *>(slot));
}

class Boolean : public Primitive {
  /// @symbol _ZN2v87Boolean9CheckCastEPNS_5ValueE
  static void CheckCast(v8::Value *obj);

public:
  bool Value() const;
  inline static Boolean *Cast(v8::Value *obj) {
    CheckCast(obj);
    return (Boolean *)obj;
  }
  inline static v8::Local<v8::Boolean> New(v8::Isolate *isolate, bool value) { return value ? True(isolate) : False(isolate); }
};

template <class T> class ReturnValue;
template <typename T> class FunctionCallbackInfo;

template <typename T> class FunctionCallbackInfo {
  inline static constexpr int kHolderIndex                  = 0;
  inline static constexpr int kIsolateIndex                 = 1;
  inline static constexpr int kReturnValueDefaultValueIndex = 2;
  inline static constexpr int kReturnValueIndex             = 3;
  inline static constexpr int kDataIndex                    = 4;
  inline static constexpr int kNewTargetIndex               = 5;

public:
  inline int Length() const { return length_; }
  inline Local<Value> operator[](int i) const {
    if (i < 0 || length_ <= i) return Undefined(GetIsolate());
    return Local<Value>(reinterpret_cast<Value *>(values_ - i));
  }
  inline Local<Object> This() const { return Local<Object>(reinterpret_cast<Object *>(values_ + 1)); }
  inline Local<Object> Holder() const { return Local<Object>(reinterpret_cast<Object *>(&implicit_args_[kHolderIndex])); }
  inline Local<Value> NewTarget() const { return Local<Value>(reinterpret_cast<Value *>(&implicit_args_[kNewTargetIndex])); }
  inline bool IsConstructCall() const { return !NewTarget()->IsUndefined(); }
  inline Local<Value> Data() const { return Local<Value>(reinterpret_cast<Value *>(&implicit_args_[kDataIndex])); }
  inline Isolate *GetIsolate() const { return *reinterpret_cast<Isolate **>(&implicit_args_[kIsolateIndex]); }
  inline ReturnValue<T> GetReturnValue() const { return ReturnValue<T>(&implicit_args_[kReturnValueIndex]); }

private:
  internal::Address *implicit_args_;
  internal::Address *values_;
  int length_;
};

template <class T> class ReturnValue {
  internal::Address *value_;

public:
  ReturnValue(internal::Address *slot)
      : value_(slot) {}
  template <typename S> inline void Set(const Local<S> handle) { *value_ = *reinterpret_cast<internal::Address *>(*handle); }
};

class TryCatch {
public:
  /// @symbol _ZN2v88TryCatchC2EPNS_7IsolateE
  TryCatch(v8::Isolate *isolate);
  ~TryCatch();
  bool HasCaught() const;
  bool CanContinue() const;
  bool HasTerminated() const;
  v8::Local<v8::Value> ReThrow();
  v8::Local<v8::Value> Exception() const;
  /// @symbol _ZNK2v88TryCatch10StackTraceENS_5LocalINS_7ContextEEE
  v8::MaybeLocal<v8::Value> StackTrace(v8::Local<v8::Context> context) const;
  v8::Local<v8::Message> Message() const;
  void Reset();
  void SetVerbose(bool value);
  void SetCaptureMessage(bool value);

  /// @skipped
  TryCatch(const TryCatch &) = delete;

  /// @skipped
  void operator=(const TryCatch &) = delete;

private:
  void *isolate_;
  TryCatch *next_;
  void *exception_;
  void *message_obj_;
  void *js_stack_comparable_address_;
  bool is_verbose_ : 1;
  bool can_continue_ : 1;
  bool capture_message_ : 1;
  bool rethrow_ : 1;
  bool has_terminated_ : 1;
};

class ExtensionConfiguration;
class ObjectTemplate;

class Isolate {
  char filler[0x10000];

public:
  /// @symbol _ZN2v87Isolate14ThrowExceptionENS_5LocalINS_5ValueEEE
  v8::Local<v8::Value> ThrowException(v8::Local<v8::Value>);

  static v8::Isolate *GetCurrent();
  v8::Local<v8::Context> GetCurrentContext();
  bool InContext();
  void Enter();
  void Exit();

  class Scope {
    Isolate *iso;

  public:
    explicit inline Scope(Isolate *iso)
        : iso(iso) {
      iso->Enter();
    }
    inline ~Scope() { iso->Exit(); }
  };
};

class Context {
public:
  void Enter();
  void Exit();
  /// @symbol _ZN2v87Context3NewEPNS_7IsolateEPNS_22ExtensionConfigurationENS_10MaybeLocalINS_14ObjectTemplateEEENS5_INS_5ValueEEE
  static v8::Local<v8::Context> New(v8::Isolate *, v8::ExtensionConfiguration *, v8::MaybeLocal<v8::ObjectTemplate>, v8::MaybeLocal<v8::Value>);
  static v8::Local<v8::Object> Global();

  class Scope {
  public:
    explicit inline Scope(Local<Context> context)
        : context_(context) {
      context_->Enter();
    }
    inline ~Scope() { context_->Exit(); }

  private:
    Local<Context> context_;
  };
};

class HandleScope {
  char filler[0x20];

public:
  /// @symbol _ZN2v811HandleScopeC2EPNS_7IsolateE
  HandleScope(v8::Isolate *isolate);
  ~HandleScope();
  /// @skipped
  HandleScope(const HandleScope &) = delete;
  /// @skipped
  void operator=(const HandleScope &) = delete;
};

class EscapableHandleScope {
  char filler[0x20];

public:
  /// @symbol _ZN2v820EscapableHandleScopeC2EPNS_7IsolateE
  EscapableHandleScope(v8::Isolate *isolate);
  /// @skipped
  EscapableHandleScope(const EscapableHandleScope &) = delete;
  /// @skipped
  void operator=(const EscapableHandleScope &) = delete;
};

enum PropertyFilter : int {
  ALL_PROPERTIES    = 0,
  ONLY_WRITABLE     = 1,
  ONLY_ENUMERABLE   = 2,
  ONLY_CONFIGURABLE = 4,
  SKIP_STRINGS      = 8,
  SKIP_SYMBOLS      = 16,
};

class Object : public Value {
  /// @symbol _ZN2v86Object9CheckCastEPNS_5ValueE
  static void CheckCast(v8::Value *obj);

public:
  inline static Object *Cast(v8::Value *obj) {
    CheckCast(obj);
    return (Object *)obj;
  }
  /// @symbol _ZN2v86Object3NewEPNS_7IsolateE
  static v8::Local<v8::Object> New(v8::Isolate *isolate);
  /// @symbol _ZN2v86Object3SetEjNS_5LocalINS_5ValueEEE
  bool Set(unsigned, v8::Local<v8::Value>);
  /// @symbol _ZN2v86Object3SetENS_5LocalINS_5ValueEEES3_
  bool Set(v8::Local<v8::Value>, v8::Local<v8::Value>);
  /// @symbol _ZN2v86Object3GetEj
  v8::Local<v8::Value> Get(unsigned);
  /// @symbol _ZN2v86Object3GetENS_5LocalINS_5ValueEEE
  v8::Local<v8::Value> Get(v8::Local<v8::Value>);
  /// @symbol _ZN2v86Object3HasENS_5LocalINS_5ValueEEE
  bool Has(v8::Local<v8::Value>);
  /// @symbol _ZN2v86Object16SetInternalFieldEiNS_5LocalINS_5ValueEEE
  void SetInternalField(int, v8::Local<v8::Value>);
  /// @symbol _ZN2v86Object32SetAlignedPointerInInternalFieldEiPv
  void SetAlignedPointerInInternalField(int, void *);

  /// @symbol _ZN2v86Object20SlowGetInternalFieldEi
  v8::Local<v8::Value> GetInternalField(int pos);
  /// @symbol _ZN2v86Object38SlowGetAlignedPointerFromInternalFieldEi
  void *GetAlignedPointerFromInternalField(int pos);

  /// @symbol _ZN2v86Object19GetOwnPropertyNamesENS_5LocalINS_7ContextEEE
  v8::Local<v8::Array> GetOwnPropertyNames(v8::Local<v8::Context>);
  /// @symbol _ZN2v86Object19GetOwnPropertyNamesENS_5LocalINS_7ContextEEENS_14PropertyFilterE
  v8::Local<v8::Array> GetOwnPropertyNames(v8::Local<v8::Context>, v8::PropertyFilter);
};

class Array : public Object {
  /// @symbol _ZN2v85Array9CheckCastEPNS_5ValueE
  static void CheckCast(v8::Value *obj);

public:
  inline static Array *Cast(Value *obj) {
    CheckCast(obj);
    return (Array *)obj;
  }
  /// @symbol _ZN2v85Array3NewEPNS_7IsolateEi
  static v8::Local<v8::Array> New(v8::Isolate *isolate, int length);
  unsigned Length() const;
};

class ArrayBuffer : public Object {

  /// @symbol _ZN2v811ArrayBuffer9CheckCastEPNS_5ValueE
  static void CheckCast(v8::Value *obj);

public:
  static v8::ArrayBuffer *Cast(v8::Value *obj) {
    CheckCast(obj);
    return (ArrayBuffer *)obj;
  }
  class Contents {
    void *data_;
    size_t byte_length_;

  public:
    Contents()
        : data_(NULL)
        , byte_length_(0) {}
    void *Data() const { return data_; }
    size_t ByteLength() const { return byte_length_; }
  };

  /// @symbol _ZN2v811ArrayBuffer11GetContentsEv
  v8::ArrayBuffer::Contents GetContents();
  /// @symbol _ZN2v811ArrayBuffer3NewEPNS_7IsolateEj
  static v8::Local<v8::ArrayBuffer> New(v8::Isolate *isolate, size_t byte_length);
};

using FunctionCallback = void (*)(v8::FunctionCallbackInfo<v8::Value> const &);

class Function : public Object {
  /// @symbol _ZN2v88Function9CheckCastEPNS_5ValueE
  static void CheckCast(v8::Value *obj);

public:
  inline static Function *Cast(Value *obj) {
    CheckCast(obj);
    return (Function *)obj;
  }
  /// @symbol _ZN2v88Function4CallENS_5LocalINS_5ValueEEEiPS3_
  v8::Local<v8::Value> Call(v8::Local<v8::Value> recv, int argc, v8::Local<v8::Value> *argv);
  /// @symbol _ZNK2v88Function11NewInstanceENS_5LocalINS_7ContextEEEiPNS1_INS_5ValueEEE
  v8::Local<v8::Object> NewInstance(v8::Local<v8::Context> context, int argc, v8::Local<v8::Value> *argv);
  /// @symbol _ZN2v88Function3NewEPNS_7IsolateEPFvRKNS_20FunctionCallbackInfoINS_5ValueEEEENS_5LocalIS4_EEi
  static v8::Local<v8::Function> New(v8::Isolate *, v8::FunctionCallback, v8::Local<v8::Value>, int);
};

enum class PropertyAttribute { None, ReadOnly, DontEnum, DontDelete };
enum class AccessControl { DEFAULT, ALL_CAN_READ, ALL_CAN_WRITE, PROHIBITS_OVERWRITING };

class Template : public Data {
public:
  /// @symbol _ZN2v88Template3SetENS_5LocalINS_4NameEEENS1_INS_4DataEEENS_17PropertyAttributeE
  void Set(v8::Local<v8::Name>, v8::Local<v8::Data>, v8::PropertyAttribute);
  void Set(v8::Local<v8::Name> name, v8::Local<v8::Data> data) { Set(name, data, PropertyAttribute::None); }

  /// @symbol _ZN2v88Template19SetAccessorPropertyENS_5LocalINS_4NameEEENS1_INS_16FunctionTemplateEEES5_NS_17PropertyAttributeENS_13AccessControlE
  void SetAccessorProperty(v8::Local<v8::Name>, v8::Local<v8::FunctionTemplate>, v8::Local<v8::FunctionTemplate>, v8::PropertyAttribute, v8::AccessControl);
  void SetAccessorProperty(v8::Local<v8::Name> name, v8::Local<v8::FunctionTemplate> getter) { SetAccessorProperty(name, getter, Local<FunctionTemplate>(), PropertyAttribute::None, AccessControl::DEFAULT); }
};

class FunctionTemplate : public Template {
public:
  inline static FunctionTemplate *Cast(Value *obj) { return (FunctionTemplate *)obj; }
  /// @symbol _ZN2v816FunctionTemplate3NewEPNS_7IsolateEPFvRKNS_20FunctionCallbackInfoINS_5ValueEEEENS_5LocalIS4_EENSA_INS_9SignatureEEEiNS_19ConstructorBehaviorE
  static v8::Local<v8::FunctionTemplate> New(v8::Isolate *isolate, v8::FunctionCallback callback, v8::Local<v8::Value> data, v8::Local<v8::Signature> signature, int length);
  static inline v8::Local<v8::FunctionTemplate> New(v8::Isolate *isolate) { return New(isolate, nullptr); }
  static inline v8::Local<v8::FunctionTemplate> New(v8::Isolate *isolate, v8::FunctionCallback callback) { return New(isolate, callback, Local<Value>()); }
  static inline v8::Local<v8::FunctionTemplate> New(v8::Isolate *isolate, v8::FunctionCallback callback, v8::Local<v8::Value> data) { return New(isolate, callback, data, Local<Signature>(), 0); }
  static inline v8::Local<v8::FunctionTemplate> New(v8::Isolate *isolate, v8::FunctionCallback callback, int length) { return New(isolate, callback, Local<Value>(), Local<Signature>(), length); }

  /// @symbol _ZN2v816FunctionTemplate7InheritENS_5LocalIS0_EE
  void Inherit(v8::Local<v8::FunctionTemplate> parent);

  /// @symbol _ZN2v816FunctionTemplate12SetClassNameENS_5LocalINS_6StringEEE
  void SetClassName(v8::Local<v8::String> name);

  /// @symbol _ZN2v816FunctionTemplate17PrototypeTemplateEv
  v8::Local<v8::ObjectTemplate> PrototypeTemplate();

  /// @symbol _ZN2v816FunctionTemplate16InstanceTemplateEv
  v8::Local<v8::ObjectTemplate> InstanceTemplate();

  /// @symbol _ZN2v816FunctionTemplate11GetFunctionENS_5LocalINS_7ContextEEE
  v8::Local<v8::Object> GetFunction(v8::Local<v8::Context>);

  /// @symbol _ZN2v816FunctionTemplate11HasInstanceENS_5LocalINS_5ValueEEE
  bool HasInstance(v8::Local<v8::Value> object);
};

class ObjectTemplate : public Template {
public:
  /// @symbol _ZN2v814ObjectTemplate11NewInstanceENS_5LocalINS_7ContextEEE
  v8::Local<v8::Object> NewInstance(v8::Local<v8::Context>);

  /// @symbol _ZN2v814ObjectTemplate17SetImmutableProtoEv
  void SetImmutableProto();

  /// @symbol _ZN2v814ObjectTemplate21SetInternalFieldCountEi
  void SetInternalFieldCount(int value);
};

template <class T> class Persistent : BaseLocal<void *> {

public:
  Persistent()
      : BaseLocal<void *>() {}
  Persistent(Isolate *iso, Local<T> local)
      : BaseLocal<void *>((void **)V8::GlobalizeReference(iso, (void *)local)) {}
  inline Local<T> Get(Isolate *iso) const { return Local<T>((T *)V8::CreateHandle(iso, *this->val_)); }
  inline void Set(void *target) { this->val_ = (void **)target; }
};

class Exception {
public:
  /// @symbol _ZN2v89Exception10RangeErrorENS_5LocalINS_6StringEEE
  static v8::Local<v8::Value> RangeError(v8::Local<v8::String> message);
  /// @symbol _ZN2v89Exception14ReferenceErrorENS_5LocalINS_6StringEEE
  static v8::Local<v8::Value> ReferenceError(v8::Local<v8::String> message);
  /// @symbol _ZN2v89Exception11SyntaxErrorENS_5LocalINS_6StringEEE
  static v8::Local<v8::Value> SyntaxError(v8::Local<v8::String> message);
  /// @symbol _ZN2v89Exception9TypeErrorENS_5LocalINS_6StringEEE
  static v8::Local<v8::Value> TypeError(v8::Local<v8::String> message);
  /// @symbol _ZN2v89Exception5ErrorENS_5LocalINS_6StringEEE
  static v8::Local<v8::Value> Error(v8::Local<v8::String> message);
};

class Promise : public Object {

public:
  class Resolver : public Object {
    /// @symbol _ZN2v87Promise8Resolver9CheckCastEPNS_5ValueE
    static void CheckCast(v8::Value *obj);

  public:
    inline static Resolver *Cast(Value *obj) {
      CheckCast(obj);
      return (Resolver *)obj;
    }
    /// @symbol _ZN2v87Promise8Resolver3NewENS_5LocalINS_7ContextEEE
    static v8::MaybeLocal<v8::Promise::Resolver> New(v8::Local<v8::Context> context);
    /// @symbol _ZN2v87Promise8Resolver6RejectENS_5LocalINS_7ContextEEENS2_INS_5ValueEEE
    v8::Maybe<bool> Resolve(v8::Local<v8::Context> context, v8::Local<v8::Value> value);
    /// @symbol _ZN2v87Promise8Resolver7ResolveENS_5LocalINS_7ContextEEENS2_INS_5ValueEEE
    v8::Maybe<bool> Reject(v8::Local<v8::Context> context, v8::Local<v8::Value> value);
  };
};

}