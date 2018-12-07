#pragma once

#include <string>
#include <unordered_map>

namespace argparser {

class arg_list {

private:
    int argc;
    const char** argv;

public:
    arg_list(int argc, const char** argv) : argc(argc), argv(argv) {
    }

    const char* peek() {
        if (argc <= 0)
            return nullptr;
        return *(argv + 1);
    }

    const char* next_or_null() {
        if (argc <= 0)
            return nullptr;
        argc--;
        return *(argv++);
    }

    const char* next() {
        const char* val = next_or_null();
        if (val == nullptr)
            throw std::out_of_range("Missing argument");
        return val;
    }

    const char* next_value_or_null() {
        const char* val = peek();
        if (val == nullptr || val[0] == '-')
            return nullptr;
        return next();
    }

    const char* next_value() {
        const char* val = next_value_or_null();
        if (val == nullptr)
            throw std::out_of_range("Missing argument");
        return val;
    }

};

}