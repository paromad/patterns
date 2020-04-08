#include "boy.h"

Boy::Boy() {
    damage_ = 15;
    speed_ = 15;
    protection_ = 20;
    price_ = 30;
}

bool Boy::treat() const {
    return false;
}

bool Boy::shield() const {
    return false;
}