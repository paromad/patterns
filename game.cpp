#include <iostream>
#include <squad.h>
#include <army.h>
#include "air_factory.h"
#include "earth_factory.h"
#include "water_factory.h"
#include "fire_factory.h"
#include "composite.h"

class Game {
public:
    void start() {
        std::cout << "Hello, nice to meet you here!\n"
                     "Now we will start playing!\n"
                     "If you want to exit, write \"exit\".\n"
                     "Сhoose one of 4 elements: "
                     "\"air\", \"water\", \"earth\" or \"fire\".\n";
        std::string command;
        std::cin >> command;
        size_t num = get_factory(command);
        if (num == -1) {
            return;
        }
        AbstractFactory *factory = nullptr;
        if (num == 0) factory = new AirFactory;
        if (num == 1) factory = new WaterFactory;
        if (num == 2) factory = new EarthFactory;
        if (num == 3) factory = new FireFactory;
        std::vector<Unit *> units;
        std::cout << "Now you can choose your warriors!\n"
                     "You can choose from 3 types: boy, girl and animal.\n"
                     "Girls and boys can attack with their magic power. Girls are stronger, but they have weaker protection.\n"
                     "Animals can't attack, but they can protect and treat girls and boys.\n"
                     "Choose wisely!\n\n";
        create_units(units, factory);
        std::cout << "You have your warriors. Now you can create squads. A squad is one or more warriors.\n"
                     "Animal can protect and treat people only from their squad!\n"
                     "You can have 1 or 2 squads.\n"
                     "Do you want to create 2 squad? Write \"yes\" or \"no\".\n";
        std::cin >> command;
        Squad squad1(""), squad2("");
        if (command == "yes") {
            create_squad(squad1, units);
            for (size_t i = 0; i < units.size(); ++i) {
                if (units[i]->number_of_squad == 0) {
                    units[i]->number_of_squad = 2;
                    squad2.add(new Leaf(units[i]));
                }
            }
            std::cout << "Choose name for 2nd squad.\n";
            std::cin >> command;
            squad2.name = command;
        } else {
            std::cout << "Choose name for squad.\n";
            std::cin >> command;
            squad1.name = command;
            for (size_t i = 0; i < units.size(); ++i) {
                squad1.add(new Leaf(units[i]));
            }
        }
        std::cout << "\nYou have in " << squad1.name << ": ";
        for (int i = 0; i < squad1.children_.size(); ++i) {
            std::cout << squad1.children_[i]->self_->name << " ";
        }
        if (squad2.children_.size() > 0) {
            std::cout << "\nYou have in " << squad2.name << ": ";
            for (int i = 0; i < squad2.children_.size(); ++i) {
                std::cout << squad2.children_[i]->self_->name << " ";
            }
        }
        Army army("Your army");
        army.add(&squad1);
        if (squad2.children_.size()) army.add(&squad2);
        std::cout << "\nCongratulations! You created your army!\n"
                     "You have " << (squad2.children_.size() ? 2 : 1) << " squads in it:\n";
        std::cout << squad1.name << " " << (squad2.children_.size() ? squad2.name : "") << "\n";
        Army opponent_army = create_opponent_army(factory, army);
        std::cout << "Opponent army already here!\n"
                     "Start fight! Good luck!\n";
    }

    int get_factory(std::string str) {
        if (str == "exit") {
            std::cout << "Goodbye!\n";
            return -1;
        }
        if (str == "air") return 0;
        if (str == "water") return 1;
        if (str == "earth") return 2;
        if (str == "fire") return 3;
        std::cout << "Please write element correctly.\n"
                     "If you want to exit, write \"exit\".\n";
        std::cin >> str;
        return get_factory(str);
    }

    void create_units(std::vector<Unit *> &units, AbstractFactory *factory) {
        factory->message();
        std::cout << "Choose one of type: \"boy\" (30 coins), \"girl\" (30 coins) or \"animal\" (15 coins).\n"
                     "If you want to finish creating warriors, write \"all\".\n";
        std::string unit;
        std::cin >> unit;
        if (unit == "all") return;
        int index = -1;
        if (unit == "girl") index = 0;
        if (unit == "boy") index = 1;
        if (unit == "animal") index = 2;
        if (index == -1) {
            std::cout << "Please, write type correctly.\n";
            return create_units(units, factory);
        }
        if (factory->can_create_unit(unit)) {
            if (index == 0) units.push_back(factory->create_girl());
            if (index == 1) units.push_back(factory->create_boy());
            if (index == 2) units.push_back(factory->create_animal());
            std::string name;
            std::cout << "Choose name for this warrior.\n";
            std::cin >> name;
            units.back()->name = name;
            return create_units(units, factory);
        }
        std::cout << "Sorry, you have not enough money.\n";
    }

    void create_squad(Squad &squad, std::vector<Unit *> units, int num = 1) {
        std::cout << "Now you creating your " << num << " squad.\n";
        std::cout << "Now you have: ";
        for (size_t i = 0; i < units.size(); ++i) {
            if (units[i]->number_of_squad == 0) std::cout << units[i]->name << ", ";
        }
        std::cout << "please choose, who will in this square. (Write one name in one time).\n";
        std::cout << "Write \"all\" when you want to finish\n";
        std::string name;
        std::cin >> name;
        while (name != "all") {
            int index = -1;
            for (size_t i = 0; i < units.size(); ++i) {
                if (units[i]->number_of_squad == 0 && units[i]->name == name) {
                    units[i]->number_of_squad = num;
                    index = i;
                }
            }
            if (index == -1) {
                std::cout << name << " isn't in your warriors.\n"
                                     "Please, write name correctly.\n";
            } else {
                squad.add(new Leaf(units[index]));
            }
            std::cout << "Write \"all\" when you want to finish\n";
            std::cin >> name;
        }
        std::cout << "Choose name for 1st squad.\n";
        std::cin >> name;
        squad.name = name;
    }

    int get_opponent_factory(AbstractFactory *factory) {
        if (dynamic_cast<AirFactory *>(factory)) return 3;
        if (dynamic_cast<WaterFactory *>(factory)) return 2;
        if (dynamic_cast<EarthFactory *>(factory)) return 1;
        return 0;
    }

    Army create_opponent_army(AbstractFactory *our_factory, const Army &our_army) {
        int num = get_opponent_factory(our_factory);
        AbstractFactory *factory = nullptr;
        if (num == 0) factory = new AirFactory;
        if (num == 1) factory = new WaterFactory;
        if (num == 2) factory = new EarthFactory;
        if (num == 3) factory = new FireFactory;
        Army army("Opponent army");
        for (int j = 0; j < our_army.children_.size(); ++j) {
            Squad *squad = dynamic_cast<Squad*>(our_army.children_[0]);
            Squad *new_squad = new Squad("");
            for (int i = 0; i < squad->children_.size(); ++i) {
                if (squad->children_[i]->name_of_unit == "girl") new_squad->add(new Leaf(factory->create_boy()));
                if (squad->children_[i]->name_of_unit == "boy") new_squad->add(new Leaf(factory->create_girl()));
                if (squad->children_[i]->name_of_unit == "animal") new_squad->add(new Leaf(factory->create_animal()));
            }
            army.children_.push_back(new_squad);
        }
        return army;
    }
};