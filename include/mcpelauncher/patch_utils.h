#pragma once

class PatchUtils {

private:
    static const char* TAG;

public:
    static void patchCallInstruction(void* patchOff, void* func, bool jump);

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