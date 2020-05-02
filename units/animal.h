#pragma once

#include "unit.h"

class Animal : public Unit {
public:
    Animal();

    bool treat() const override;

    bool shield() const override;
};