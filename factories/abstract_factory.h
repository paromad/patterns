#pragma once
#include <string>
#include "girl.h"
#include "boy.h"
#include "animal.h"

class AbstractFactory {
public:
    int money_ = 100;
    std::string price_name[3] = {"girl", "boy", "animal"};
    int price[3] = {30, 30, 15};
    bool can_create_unit(std::string unit);
    virtual Girl* create_girl() = 0;
    virtual Boy* create_boy() = 0;
    virtual Animal* create_animal() = 0;
    virtual ~AbstractFactory() = default;
    void message() const;
};