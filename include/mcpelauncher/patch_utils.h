#pragma once

#include <cstdlib>

class PatchUtils {

private:
    static const char* TAG;

public:
    class VtableReplaceHelper {

    private:
        void* lib;
        void** vtable;
        void** referenceVtable;

    public:
        VtableReplaceHelper(void* lib, void** vtable, void** referenceVtable) : lib(lib), vtable(vtable),
                                                                                referenceVtable(referenceVtable) {}

        void replace(void* sym, void* replacement);

        void replace(const char* name, void* replacement);

        template <typename T>
        void replace(void* sym, T replacement) {
            replace(sym, memberFuncCast(replacement));
        }

        template <typename T>
        void replace(const char* name, T replacement) {
            replace(name, memberFuncCast(replacement));
        }

    };

    static void patchCallInstruction(void* patchOff, void* func, bool jump);

    static size_t getVtableSize(void** vtable);

    template <typename T>
    static void* memberFuncCast(T func) {
        union {
            T func;
            void* ptr;
        } u;
        u.func = func;
        return u.ptr;
    }

};