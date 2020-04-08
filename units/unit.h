#pragma once

#include <string>

class Unit {
public:
    double health_ = 100;
    double damage_ = 0;
    double speed_ = 0;
    const char *weapon_ = "";
    double protection_ = 0;
    double price_ = 0;

    virtual bool treat() const = 0;

    virtual bool shield() const = 0;

    virtual ~Unit() = default;
};