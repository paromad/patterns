#pragma once

#include "abstract_factory.h"

class AirFactory : public AbstractFactory {
public:
    Girl *create_girl();

    Boy *create_boy();

    Animal *create_animal();
};

class AirGirl : public Girl {
public:
    AirGirl();
};

class AirBoy : public Boy {
public:
    AirBoy();
};

class AirAnimal : public Animal {
};