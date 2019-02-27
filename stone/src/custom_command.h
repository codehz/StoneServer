#pragma once

#include <minecraft/CommandOrigin.h>
#include <vector>

extern CommandOrigin *current_orig;

void registerCustomEnum(mcpe::string name, std::vector<mcpe::string> list);