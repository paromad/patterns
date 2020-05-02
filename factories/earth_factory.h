#pragma once

#include "abstract_factory.h"

class EarthFactory : public AbstractFactory {
public:
    Girl *create_girl();

    Boy *create_boy();

    Animal *create_animal();
};

class EarthGirl : public Girl {
public:
    EarthGirl();
};

class EarthBoy : public Boy {
public:
    EarthBoy();
};

class EarthAnimal : public Animal {
};