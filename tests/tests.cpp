#include <gtest/gtest.h>
#include "girl.h"
#include "boy.h"
#include "animal.h"
#include "abstract_factory.h"
#include "air_factory.h"
#include "water_factory.h"
#include "earth_factory.h"
#include "fire_factory.h"

TEST(units, girl) {
    Girl girl;
    ASSERT_FALSE(girl.shield());
    ASSERT_FALSE(girl.treat());
    Unit* unit_girl = new Girl;
    ASSERT_FALSE(unit_girl->shield());
    ASSERT_FALSE(unit_girl->treat());
    delete unit_girl;
}

TEST(units, boy) {
    Boy boy;
    ASSERT_FALSE(boy.shield());
    ASSERT_FALSE(boy.treat());
    Unit* unit_boy = new Boy;
    ASSERT_FALSE(unit_boy->shield());
    ASSERT_FALSE(unit_boy->treat());
    delete unit_boy;
}

TEST(units, animal) {
    Animal animal;
    ASSERT_FALSE(animal.shield());
    ASSERT_FALSE(animal.treat());
    Unit* unit_animal = new Animal;
    ASSERT_FALSE(unit_animal->shield());
    ASSERT_FALSE(unit_animal->treat());
    delete unit_animal;
}

TEST(factories, air) {
    AbstractFactory* factory = new AirFactory;
    Girl* girl = factory->create_girl();
    ASSERT_STREQ(girl->weapon_, "Air funnel");
    delete girl;
    Boy* boy = factory->create_boy();
    ASSERT_STREQ(girl->weapon_, "Air swipe");
    delete boy;
    delete factory;
}

TEST(factories, water) {
    AbstractFactory* factory = new WaterFactory;
    Girl* girl = factory->create_girl();
    ASSERT_STREQ(girl->weapon_, "Ice arrows");
    delete girl;
    Boy* boy = factory->create_boy();
    ASSERT_STREQ(girl->weapon_, "Tsunami");
    delete boy;
    delete factory;
}

TEST(factories, earth) {
    AbstractFactory* factory = new EarthFactory;
    Girl* girl = factory->create_girl();
    ASSERT_STREQ(girl->weapon_, "Stone bomb");
    delete girl;
    Boy* boy = factory->create_boy();
    ASSERT_STREQ(girl->weapon_, "Stone rims");
    delete boy;
    delete factory;
}

TEST(factories, fire) {
    AbstractFactory* factory = new FireFactory;
    Girl* girl = factory->create_girl();
    ASSERT_STREQ(girl->weapon_, "Fire funnel");
    delete girl;
    Boy* boy = factory->create_boy();
    ASSERT_STREQ(girl->weapon_, "Fire blade");
    delete boy;
    delete factory;
}

TEST(factories_creating, first) {
    AbstractFactory* factory = new AirFactory;
    ASSERT_TRUE(factory->can_create_unit("girl"));
    ASSERT_TRUE(factory->can_create_unit("boy"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_FALSE(factory->can_create_unit("girl"));
    delete factory;
}

TEST(factories_creating, second) {
    AbstractFactory* factory = new AirFactory;
    ASSERT_TRUE(factory->can_create_unit("boy"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("girl"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_FALSE(factory->can_create_unit("boy"));
    delete factory;
}

TEST(factories_creating, third) {
    AbstractFactory* factory = new AirFactory;
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_FALSE(factory->can_create_unit("boy"));
    delete factory;
}

TEST(factories_creating, fourth) {
    AbstractFactory* factory = new AirFactory;
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_FALSE(factory->can_create_unit("boy"));
    delete factory;
    AbstractFactory* other_factory = new AirFactory;
    ASSERT_TRUE(other_factory->can_create_unit("boy"));
    ASSERT_TRUE(other_factory->can_create_unit("animal"));
    ASSERT_TRUE(other_factory->can_create_unit("girl"));
    ASSERT_TRUE(other_factory->can_create_unit("animal"));
    ASSERT_FALSE(other_factory->can_create_unit("boy"));
    delete other_factory;
}