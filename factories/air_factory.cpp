#include "air_factory.h"

Girl *AirFactory::create_girl() {
    return new AirGirl;
}

Boy *AirFactory::create_boy() {
    return new AirBoy;
}

Animal *AirFactory::create_animal() {
    return new AirAnimal;
}

AirGirl::AirGirl() {
    weapon_ = "Air funnel";
}

AirBoy::AirBoy() {
    weapon_ = "Air swipe";
}