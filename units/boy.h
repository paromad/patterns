#pragma once

#include "unit.h"

class Boy : public Unit {
public:
    Boy();

    bool treat() const override;

    bool shield() const override;

    double get_damage() const override;

    double get_health() const override;
};