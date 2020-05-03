#pragma once

#include "abstract_factory.h"

class WaterFactory : public AbstractFactory {
public:
    Girl *create_girl() override;

    Boy *create_boy() override;

    Animal *create_animal() override;

    ~WaterFactory() override = default;
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