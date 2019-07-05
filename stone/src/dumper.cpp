#include "dumper.h"
#include <cstdio>
#include <cstdlib>
#include <cxxabi.h>
#include <execinfo.h>
#include <hybris/dlfcn.h>

void dump_backtrace() {
  void *array[200];
  int count         = backtrace(array, 200);
  char **symbols    = backtrace_symbols(array, count);
  char *nameBuf     = (char *)malloc(256);
  size_t nameBufLen = 256;
  for (int i = 2; i < count; i++) {
    if (symbols[i] == nullptr) {
      printf("#%i unk [0x%04x]\n", i, (int)array[i]);
      continue;
    }
    if (symbols[i][0] == '[') { // unknown symbol
      Dl_info symInfo;
      if (hybris_dladdr(array[i], &symInfo)) {
        int status = 0;
        nameBuf    = abi::__cxa_demangle(symInfo.dli_sname, nameBuf, &nameBufLen, &status);
        printf("#%i HYBRIS %s(%s)+%i in %s+0x%04x [0x%04x]\n", i, nameBuf, symInfo.dli_sname,
               (unsigned int)array[i] - (unsigned int)symInfo.dli_saddr, symInfo.dli_fname, (unsigned int)array[i] - (unsigned int)symInfo.dli_fbase,
               (int)array[i]);
        continue;
      }
    }
    printf("#%i %s\n", i, symbols[i]);
  }
  free(nameBuf);
}