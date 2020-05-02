#pragma once

#include "unit.h"

class Girl : public Unit {
public:
    Girl();

    bool treat() const override;

    bool shield() const override;
};