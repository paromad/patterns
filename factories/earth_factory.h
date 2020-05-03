#pragma once

#include "abstract_factory.h"

class EarthFactory : public AbstractFactory {
public:
    Girl *create_girl() override;

    Boy *create_boy() override;

    Animal *create_animal() override;

    ~EarthFactory() override = default;
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