#pragma once

#include <unit.h>
#include <vector>

class Component : public Unit {
public:
    Unit *self_;

    Component() {};

    Component(Unit *a);

    ~Component() override;

    virtual bool is_composite();
};

class Leaf : public Component {
public:
    Leaf() = default;
    Leaf(Unit *);

    bool treat() const override;

    double get_damage() const override;

    double get_health() const override;
};

class Composite : public Component {
public:
    std::vector<Component *> children_;

    Composite() {};

    bool is_composite() override;

    void add(Component *);

    void remove();

    bool treat() const override;

    double get_damage() const override;

    double get_health() const override;
};
