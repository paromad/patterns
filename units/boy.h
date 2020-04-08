#pragma once

#include "unit.h"

class Boy : public Unit {
public:
    Boy();

    bool treat() const;

    bool shield() const;
};