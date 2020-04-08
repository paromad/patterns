#include "earth_factory.h"

Girl *EarthFactory::create_girl() {
    return new EarthGirl;
}

Boy *EarthFactory::create_boy() {
    return new EarthBoy;
}

Animal *EarthFactory::create_animal() {
    return new EarthAnimal;
}

EarthGirl::EarthGirl() {
    weapon_ = "Stone bomb";
}

EarthBoy::EarthBoy() {
    weapon_ = "Stone rims";
}