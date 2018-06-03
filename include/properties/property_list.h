#pragma once

#include <unordered_map>
#include <iostream>

namespace properties {

class property_base {

public:
    virtual void parse_value(std::string const& value) = 0;

};

class property_list {

private:
    std::unordered_map<std::string, property_base*> prop;
    std::unordered_map<std::string, std::string> unknown_props;

public:
    property_list() {}

    void register_property(std::string name, property_base* prop) {
        this->prop.insert({name, prop});
    }

    void set_property(std::string const& name, std::string const& value) {
        auto it = prop.find(name);
        if (it == prop.end()) {
            unknown_props[name] = value;
        } else {
            it->second->parse_value(value);
        }
    }

    void load(std::istream& stream) {
        std::string line;
        while (std::getline(stream, line)) {
            if (line.length() > 0 && line[0] == '#')
                continue;
            size_t i = line.find('=');
            if (i == std::string::npos)
                continue;
            set_property(line.substr(0, i), line.substr(i + 1));
        }
    }

};

}