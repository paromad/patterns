#include <gtest/gtest.h>
#include "squad.h"
#include "composite.h"
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
    ASSERT_FALSE(girl.treat());
    Unit* unit_girl = new Girl;
    ASSERT_FALSE(unit_girl->treat());
    delete unit_girl;
}

TEST(units, boy) {
    Boy boy;
    ASSERT_FALSE(boy.treat());
    Unit* unit_boy = new Boy;
    ASSERT_FALSE(unit_boy->treat());
    delete unit_boy;
}

TEST(units, animal) {
    Animal animal;
    ASSERT_FALSE(animal.treat());
    Unit* unit_animal = new Animal;
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
    ASSERT_TRUE(factory->can_create_unit("girl"));
    ASSERT_TRUE(factory->can_create_unit("boy"));
    ASSERT_FALSE(factory->can_create_unit("girl"));
    delete factory;
}

TEST(factories_creating, second) {
    AbstractFactory* factory = new AirFactory;
    ASSERT_TRUE(factory->can_create_unit("boy"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("girl"));
    ASSERT_TRUE(factory->can_create_unit("animal"));
    ASSERT_TRUE(factory->can_create_unit("girl"));
    ASSERT_TRUE(factory->can_create_unit("boy"));
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
    ASSERT_TRUE(factory->can_create_unit("girl"));
    ASSERT_TRUE(factory->can_create_unit("boy"));
    ASSERT_FALSE(other_factory->can_create_unit("boy"));
    delete other_factory;
}

TEST(structure, childrens) {
    Component* a = new Leaf;
    ASSERT_EQ(a->health_, 100);
    ASSERT_EQ(a->odd, 20);
    ASSERT_FALSE(a->is_composite());
    delete a;
    Component* b = new Composite;
    ASSERT_EQ(b->health_, 100);
    ASSERT_EQ(b->odd, 20);
    ASSERT_TRUE(b->is_composite());
    delete b;
}

TEST(squad, first) {
    Unit* a = new AirGirl;
    Unit* b = new AirBoy;
    Squad s("squad");
    s.add(new Leaf(a));
    s.add(new Leaf(b));
    ASSERT_EQ(s.children_[0]->self_->name_of_unit, a->name_of_unit);
    ASSERT_STREQ(s.children_[1]->self_->weapon_, b->weapon_);
    delete a;
    delete b;
}

TEST (army, first) {
    Unit* a = new AirGirl;
    Unit* b = new AirBoy;
    Squad s("squad");
    s.add(new Leaf(a));
    s.add(new Leaf(b));
    ASSERT_EQ(s.children_[0]->self_->name_of_unit, a->name_of_unit);
    ASSERT_STREQ(s.children_[1]->self_->weapon_, b->weapon_);
    delete a;
    delete b;
}