#include "girl.h"

Girl::Girl() {
    damage_ = 15;
    speed_ = 20;
    protection_ = 5;
    price_ = 30;
}

bool Girl::treat() const {
    return false;
}

bool Girl::shield() const {
    return false;
}

double Girl::get_damage() const {
    return damage_ * health_ * odd;
}

double Girl::get_health() const {
    return health_;
}