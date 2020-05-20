#pragma once

#include "abstract_factory.h"

class FireFactory : public AbstractFactory {
public:
    Girl *create_girl() override;

    Boy *create_boy() override;

    Animal *create_animal() override;

    ~FireFactory() override = default;
};

class FireGirl : public Girl {
public:
    FireGirl();
};

class FireBoy : public Boy {
public:
    FireBoy();
};

class FireAnimal : public Animal {
};