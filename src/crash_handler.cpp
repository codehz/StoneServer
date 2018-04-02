#include <mcpelauncher/crash_handler.h>

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <csignal>
#include <cxxabi.h>
#include <execinfo.h>
#include <hybris/dlfcn.h>


bool CrashHandler::hasCrashed = false;

void CrashHandler::handleSignal(int signal, void *aptr) {
    printf("Signal %i received\n", signal);
    if (hasCrashed)
        return;
    hasCrashed = true;
    void** ptr = &aptr;
    void *array[25];
    int count = backtrace(array, 25);
    char **symbols = backtrace_symbols(array, count);
    char *nameBuf = (char*) malloc(256);
    size_t nameBufLen = 256;
    printf("Backtrace elements: %i\n", count);
    for (int i = 0; i < count; i++) {
        if (symbols[i] == nullptr) {
            printf("#%i unk [0x%04x]\n", i, (int)array[i]);
            continue;
        }
        if (symbols[i][0] == '[') { // unknown symbol
            Dl_info symInfo;
            if (hybris_dladdr(array[i], &symInfo)) {
                int status = 0;
                nameBuf = abi::__cxa_demangle(symInfo.dli_sname, nameBuf, &nameBufLen, &status);
                printf("#%i HYBRIS %s+%i in %s+0x%04x [0x%04x]\n", i, nameBuf, (unsigned int) array[i] - (unsigned int) symInfo.dli_saddr, symInfo.dli_fname, (unsigned int) array[i] - (unsigned int) symInfo.dli_fbase, (int)array[i]);
                continue;
            }
        }
        printf("#%i %s\n", i, symbols[i]);
    }
    printf("Dumping stack...\n");
    for (int i = 0; i < 1000; i++) {
        void* pptr = *ptr;
        Dl_info symInfo;
        if (hybris_dladdr(pptr, &symInfo) && symInfo.dli_sname != nullptr && strlen(symInfo.dli_sname) > 0) {
            int status = 0;
            nameBuf = abi::__cxa_demangle(symInfo.dli_sname, nameBuf, &nameBufLen, &status);
            printf("#%i HYBRIS %s+%i in %s+0x%04x [0x%04x]\n", i, nameBuf, (unsigned int) pptr - (unsigned int) symInfo.dli_saddr, symInfo.dli_fname, (unsigned int) pptr - (unsigned int) symInfo.dli_fbase, (int)pptr);
        }
        ptr++;
    }
    abort();
}

void CrashHandler::registerCrashHandler() {
    struct sigaction act;
    act.sa_handler = (void (*)(int)) handleSignal;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGSEGV, &act, 0);
    sigaction(SIGABRT, &act, 0);
}