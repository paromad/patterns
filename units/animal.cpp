#include "animal.h"

Animal::Animal() {
    damage_ = 0;
    speed_ = 10;
    weapon_ = "teeth and claws";
    protection_ = 30;
    price_ = 15;
}

bool Animal::treat() const {
    return false;
}

bool Animal::shield() const {
    return false;
}

double Animal::get_damage() const {
    return damage_;
}

double Animal::get_health() const {
    return health_;
}