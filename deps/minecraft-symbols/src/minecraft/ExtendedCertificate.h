#pragma once

#include "std/string.h"

class Certificate;

struct ExtendedCertificate {
    static mcpe::string getXuid(Certificate const&);
};