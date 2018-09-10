#pragma once

#include "std/function.h"
#include "Xbox.h"

namespace Social {

enum class SignInResult {
    Success, Error
};

class XboxLiveUser;

class User {

public:
    Social::XboxLiveUser* getLiveUser() const;

};


class XboxLiveUser {

public:
    /// @symbol _ZN6Social12XboxLiveUser22_handleUISignInNoErrorERN4xbox8services6system14sign_in_resultESt8functionIFvNS_12SignInResultEbEE
    void _handleUISignInNoError(xbox::services::system::sign_in_result&, mcpe::function<void (Social::SignInResult, bool)>);

};

}
