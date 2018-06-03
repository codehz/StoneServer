#pragma once

#include <string>
#include <cstring>
#include <stdexcept>
#include "property_list.h"

namespace properties {

template<typename T>
class property : public property_base {

private:
    T value;

public:
    property(property_list& p, std::string const& name, T def) : value(def) {
        p.register_property(name, this);
    }

    T const& get() const {
        return value;
    }

    operator T const&() const {
        return value;
    }

    void set(T val) {
        this->value = std::move(val);
    }

    void parse_value(std::string const& value) override;

    std::string serialize_value() override;

};

template<>
inline void property<std::string>::parse_value(std::string const& value) {
    this->value = value;
}
template<>
inline std::string property<std::string>::serialize_value() {
    return value;
}

template<>
inline void property<int>::parse_value(std::string const& value) {
    this->value = std::stoi(value);
}
template<>
inline std::string property<int>::serialize_value() {
    return std::to_string(value);
}

template<>
inline void property<bool>::parse_value(std::string const& value) {
    const char* v = value.c_str();
    if (strcmp(v, "1") == 0 || strcasecmp(v, "true") == 0 || strcasecmp(v, "on") == 0 || strcasecmp(v, "yes") == 0)
        this->value = true;
    else if (strcmp(v, "0") == 0 || strcasecmp(v, "false") == 0 || strcasecmp(v, "off") == 0 || strcasecmp(v, "no") == 0)
        this->value = false;
    else
        throw std::invalid_argument("Invalid boolean value");
}
template<>
inline std::string property<bool>::serialize_value() {
    return value ? "true" : "false";
}

}