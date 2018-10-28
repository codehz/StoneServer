#pragma once

#include "std/string.h"
#include <vector>

class Keyboard {

public:

    static void feed(unsigned char, int);
    static void feedText(mcpe::string const&, bool, unsigned char);

    static int* _states;
    static std::vector<int>* _inputCaretLocation;

};