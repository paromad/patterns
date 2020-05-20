#pragma once

#include "composite.h"
#include <vector>

class Army : public Composite {
public:
    std::string name;
    Army(std::string name_): name(name_) {};
};