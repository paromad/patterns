#pragma once

#include "unit.h"

class Girl : public Unit {
public:
    Girl();

    bool treat() const override;

    double get_damage() const override;

    double get_health() const override;
};