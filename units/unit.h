#pragma once

#include <string>

class Unit {
public:
    double odd = 20;
    double health_ = 100;
    double damage_ = 0;
    double speed_ = 0;
    const char *weapon_ = "";
    double protection_ = 0;
    double price_ = 0;
    std::string name_of_unit;
    std::string name;
    int number_of_squad = 0;

    Unit() : health_(100), weapon_("") {};

    virtual bool treat() const = 0;

    virtual ~Unit() = default;

    virtual double get_damage() const = 0;

    virtual double get_health() const = 0;
};