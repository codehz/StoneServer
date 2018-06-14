#pragma once

#include <unordered_map>
#include <iostream>

namespace properties {

class property_list {

private:
    struct property_def {
        std::function<void (std::string const&)> parse_value;
        std::function<std::string ()> serialize_value;
    };

    std::unordered_map<std::string, property_def> prop;
    std::unordered_map<std::string, std::string> unknown_props;

public:
    property_list() {}

    void register_property(std::string name, std::function<void (std::string const&)> parse_value,
                           std::function<std::string ()> serialize_value) {
        this->prop.insert({name, {parse_value, serialize_value}});
    }

    void set_property(std::string const& name, std::string const& value) {
        auto it = prop.find(name);
        if (it == prop.end()) {
            unknown_props[name] = value;
        } else {
            it->second.parse_value(value);
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

    void save(std::ostream& stream) {
        for (auto const& p : prop)
            stream << p.first << '=' << p.second.serialize_value() << '\n';
    }

};

}