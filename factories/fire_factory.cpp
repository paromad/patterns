#include "fire_factory.h"

Girl *FireFactory::create_girl() {
    return new FireGirl;
}

Boy *FireFactory::create_boy() {
    return new FireBoy;
}

Animal *FireFactory::create_animal() {
    return new FireAnimal;
}

FireGirl::FireGirl() {
    weapon_ = "Fire funnel";
}

FireBoy::FireBoy() {
    weapon_ = "Fire blade";
}