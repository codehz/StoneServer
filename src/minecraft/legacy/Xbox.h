#pragma once

#include <memory>
#include <vector>
#include "../std/string.h"

namespace Legacy {

namespace Beta_1_8 {

namespace xbox {
namespace services {

struct local_config {

    void** vtable;

    /// @vtable xbox::services::local_config _ZN4xbox8services12local_config28get_value_from_local_storageERKSsS3_S3_
    mcpe::string get_value_from_local_storage(mcpe::string const& value, mcpe::string const& u1 = mcpe::string(), mcpe::string const& u2 = mcpe::string());

};

}
}

}

}