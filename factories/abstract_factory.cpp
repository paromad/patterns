#include "abstract_factory.h"
#include <string>
#include <iostream>

bool AbstractFactory::can_create_unit(const std::string &unit) {
    int num = -1;
    for (int i = 0; i < 3; ++i) {
        if (price_name[i] == unit) num = i;
    }
    if (num != -1) {
        if (money_ >= price[num]) {
            money_ -= price[num];
            return true;
        }
    }
    return false;
}

void AbstractFactory::message() const {
    std::cout << "Now you have " << money_ << " coins.\n";
}