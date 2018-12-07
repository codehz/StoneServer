#pragma once

#include <cstring>
#include <strings.h>
#include "arg_parser.h"

namespace argparser {

template <typename T>
class arg {

private:
    T value;

    void handle_value(arg_list& list);

public:
    arg(arg_parser& parser, std::string const& name, std::string const& shortname, std::string const& desc, T def = T())
            : value(def) {
        parser.add_arg(name, shortname, desc, std::bind(&arg<T>::handle_value, this, std::placeholders::_1));
    }

    T const& get() const {
        return value;
    }

    operator T const&() const {
        return value;
    }

};

template <>
void arg<std::string>::handle_value(arg_list& list) {
    value = list.next();
}

template <>
void arg<int>::handle_value(arg_list& list) {
    value = std::stoi(list.next());
}

template <>
void arg<float>::handle_value(arg_list& list) {
    value = std::stof(list.next());
}

template <>
void arg<bool>::handle_value(arg_list& list) {
    const char* v = list.next_value_or_null();
    if (v == nullptr ||
            strcmp(v, "1") == 0 || strcasecmp(v, "true") == 0 || strcasecmp(v, "on") == 0 || strcasecmp(v, "yes") == 0)
        value = true;
    else if (strcmp(v, "0") == 0 || strcasecmp(v, "false") == 0 || strcasecmp(v, "off") == 0 || strcasecmp(v, "no") == 0)
        value = false;
    else
        throw std::invalid_argument("Invalid boolean value");
}

}