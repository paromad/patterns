#pragma once

#include "abstract_factory.h"

class WaterFactory : public AbstractFactory {
public:
    Girl *create_girl();

    Boy *create_boy();

    Animal *create_animal();
};

class WaterGirl : public Girl {
public:
    WaterGirl();
};

class WaterBoy : public Boy {
public:
    WaterBoy();
};

class WaterAnimal : public Animal {
};