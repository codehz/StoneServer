#pragma once

namespace Legacy {

namespace Pre_1_8 {

class App {

public:
    void** vtable;

    /* Pre 1.8 */
    /// @vtable App _ZN3App4quitEv
    void quit();

};

}

}