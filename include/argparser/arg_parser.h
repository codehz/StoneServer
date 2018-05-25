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
    struct help_entry {
        std::string name, shortname, desc;
    };
    std::unordered_map<std::string, handler> handlers;
    std::vector<help_entry> help_entries;

public:
    arg_parser() {
        help_entries.push_back({"--help", "-h", "Show this help information"});
    }

    bool parse(int argc, const char** argv) {
        arg_list list (argc, argv);
        if (list.next_or_null() == nullptr)
            return false;
        const char* key;
        while ((key = list.next_or_null()) != nullptr) {
            auto handler = handlers.find(key);
            if (handler == handlers.end()) {
                if (strcmp(key, "-h") == 0 || strcmp(key, "--help") == 0) {
                    print_help();
                    return false;
                }
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
        help_entries.push_back({name, shortname, desc});
    }

    void print_help() {
        printf("Program Help\n");
        for (auto const& e : help_entries)
            printf("%-2s %-15s %s\n", e.shortname.c_str(), e.name.c_str(), e.desc.c_str());
    }

};

}