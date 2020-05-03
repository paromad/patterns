#pragma once

#include "abstract_factory.h"

class AirFactory : public AbstractFactory {
public:
    Girl *create_girl() override;

    Boy *create_boy() override;

    Animal *create_animal() override;

    ~AirFactory() override = default;
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