#pragma once

#include <string>

class Unit {
public:
    const double odd = 0.05;
    double health_ = 100;
    double damage_ = 0;
    double speed_ = 0;
    const char *weapon_ = "";
    double protection_ = 0;
    double price_ = 0;

    virtual bool treat() const = 0;

    virtual bool shield() const = 0;

    virtual ~Unit() = default;

    virtual double get_damage() const = 0;

    virtual double get_health() const = 0;
};