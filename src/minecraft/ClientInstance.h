#pragma once

namespace Social { class User; }

class ClientInstance {

public:
    std::shared_ptr<Social::User> getUser();


    void _startLeaveGame();

    void _syncDestroyGame();

};