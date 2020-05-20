#pragma once

#include "composite.h"
#include <vector>

class Squad : public Composite {
public:
    std::string name;
    Squad(std::string name_): name(name_) {};
};