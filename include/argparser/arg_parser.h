#pragma once

#include <string>
#include <unordered_map>
#include <functional>
#include "arg_list.h"

namespace argparser {

class arg_parser {

public:
    using handler = std::function<void (arg_list&)>;

private:
    std::unordered_map<std::string, handler> handlers;

public:
    bool parse(int argc, const char** argv) {
        arg_list list (argc, argv);
        if (list.next_or_null() == nullptr)
            return false;
        const char* key;
        while ((key = list.next_or_null()) != nullptr) {
            auto handler = handlers.find(key);
            if (handler == handlers.end()) {
                printf("Unknown argument: %s\n", key);
                return false;
            }
            try {
                handler->second(list);
            } catch (std::exception& e) {
                printf("Invalid argument value for %s: %s", key, e.what());
                return false;
            }
        }
        return true;
    }

    void add_arg(std::string const& name, std::string const& shortname, std::string const& desc, handler h) {
        handlers[name] = handlers[shortname] = h;
    }

};

}