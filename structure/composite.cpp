#include "composite.h"

Component::Component(Unit *a) {
    self_ = a;
}

Component::~Component() {
    delete self_;
}

bool Component::is_composite() {
    return false;
}

Leaf::Leaf(Unit *a) {
    self_ = a;
}

bool Leaf::treat() const {
    return self_->treat();
}

double Leaf::get_damage() const {
    return self_->damage_;
}

double Leaf::get_health() const {
    return self_->health_;
}

bool Composite::is_composite() {
    return true;
}

void Composite::add(Component *a) {
    children_.push_back(a);
}

void Composite::remove() {
    if (children_.size()) children_.pop_back();
}

bool Composite::treat() const {
    bool treat = false;
    for (int i= 0; i < children_.size(); ++i) {
        treat = true;
    }
    return treat;
}

double Composite::get_damage() const {
    double damage = 0;
    for (size_t i = 0; i < children_.size(); ++i) {
        damage += children_[i]->damage_;
    }
    return damage;
}

double Composite::get_health() const {
    double health = 0;
    for (size_t i = 0; i < children_.size(); ++i) {
        health += children_[i]->health_;
    }
    return health;
}
