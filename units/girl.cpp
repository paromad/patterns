#include "girl.h"

Girl::Girl() {
    damage_ = 25;
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