#include "boy.h"

Boy::Boy() {
    damage_ = 15;
    speed_ = 15;
    protection_ = 10;
    price_ = 30;
    name_of_unit = "boy";
}

bool Boy::treat() const {
    return false;
}

double Boy::get_damage() const {
    return damage_ * health_ / odd;
}

double Boy::get_health() const {
    return health_;
}