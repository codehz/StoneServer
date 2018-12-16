#include <codecvt>
#include <locale>
#include <minecraft/V8.h>
#include <stone/server_hook.h>
#include <wchar.h>

namespace {
using namespace v8;

template <class Facet> struct deletable_facet : Facet {
  template <class... Args>
  deletable_facet(Args &&... args)
      : Facet(std::forward<Args>(args)...) {}
  ~deletable_facet() {}
};

SHook(void, _ZN9ScriptApi13LogV8CallbackERKN2v820FunctionCallbackInfoINS0_5ValueEEE, FunctionCallbackInfo<Value> const &info) {
  if (info.Length() != 1 || !info[0]->IsString()) {
    Log::info("Scripting", "Failed to print log");
    return;
  }
  Local<String> str = String::Cast(info[0]);
  unsigned short buffer[str->Length() + 1];
  str->Write(buffer);
  std::wstring_convert<deletable_facet<std::codecvt<char16_t, char, std::mbstate_t>>, char16_t> cvt;
  std::string content = cvt.to_bytes((char16_t *)buffer);
  Log::info("Scripting", "log: %s", content.c_str());
}

} // namespace