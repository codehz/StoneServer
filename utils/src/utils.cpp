#include <cstdlib>
#include <cxxabi.h>
#include <minecraft/fix.h>
#include <stone/hook_helper.h>
#include <stone/utils.h>

void *&MinecraftHandle() {
  static void *address;
  return address;
}

std::string GetEnvironmentVariableOrDefault(const std::string &variable_name, const std::string &default_value) {
  const char *value = getenv(variable_name.c_str());
  return value ? value : default_value;
}

void dump_vtable(XPointer vtable, int size) {
  for (int i = 0; i < size; i++) {
    auto target = vtable[i];
    printf("%2d: %p\t", i, target);
    Dl_info info;
    if (target && hybris_dladdr(target, &info)) {
      size_t bufferlen = 256;
      char buffer[256];
      int status = 0;
      abi::__cxa_demangle(info.dli_sname, buffer, &bufferlen, &status);
      printf("%s\n", buffer);
    } else {
      printf("\n");
    }
  }
}