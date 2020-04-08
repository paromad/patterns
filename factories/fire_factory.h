#pragma once

#include "abstract_factory.h"

class FireFactory : public AbstractFactory {
public:
    Girl *create_girl();

    Boy *create_boy();

    Animal *create_animal();
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