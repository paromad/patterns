#include "water_factory.h"

Girl *WaterFactory::create_girl() {
    return new WaterGirl;
}

Boy *WaterFactory::create_boy() {
    return new WaterBoy;
}

Animal *WaterFactory::create_animal() {
    return new WaterAnimal;
}

WaterGirl::WaterGirl() {
    weapon_ = "Ice arrows";
}

WaterBoy::WaterBoy() {
    weapon_ = "Tsunami";
}