#pragma once

class AppPlatform;
struct AppContext {
    char filler[0x10];
    AppPlatform* platform;
    bool doRender;
};

class App {

public:
    void** vtable;

    void init(AppContext& ctx);

    /// @vtable App _ZN3App4quitEv
    void quit();

    /// @vtable App _ZN3App10wantToQuitEv
    bool wantToQuit();

};