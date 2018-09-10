#pragma once

namespace mce {

class UUID {

public:

    static mce::UUID* EMPTY;

    static mce::UUID fromString(mcpe::string const&);

    char filler[0x10];

    mcpe::string asString() const;

};

}