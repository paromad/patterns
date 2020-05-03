#pragma once

#include <unit.h>
#include <vector>

class Component : public Unit {
protected:
    Unit *self_;
    Unit *parent_;
public:
    Component(Unit *a, Unit *b = nullptr);

    ~Component() override;

    virtual void add(Unit *) = 0;

    virtual void remove() = 0;

    virtual bool is_composite();
};

class Leaf : public Component {
public:
    double get_damage() const override;

    double get_health() const override;
};

class Composite : public Component {
protected:
    std::vector<Unit *> children_;
public:
    bool is_composite() override;

    void add(Unit *) override;

    void remove() override;

    double get_damage() const override;

    double get_health() const override;
};
