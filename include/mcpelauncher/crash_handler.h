#pragma once

class CrashHandler {

private:
    static bool hasCrashed;

    static void handleSignal(int signal, void* aptr);

public:
    static void registerCrashHandler();

};