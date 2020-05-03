#include <iostream>
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
                     "If you want to exit, write \"exit\"\n"
                     "Сhoose one of 4 elements: "
                     "\"air\", \"water\", \"earth\" or \"fire\"\n";
        std::string str;
        std::cin >> str;
        size_t num = get_factory(str);
        if (num == -1) {
            return;
        }
        AirFactory f;
        std::vector<Unit *> units;

    }

    size_t get_factory(std::string str) {
        if (str == "exit") {
            std::cout << "Goodbye!\n";
            return -1;
        }
        if (str == "air") return 0;
        if (str == "water") return 1;
        if (str == "earth") return 2;
        if (str == "fire") return 3;
        std::cout << "Please write element correctly"
                     "If you want to exit, write \"exit\"";
        std::cin >> str;
        return get_factory(str);
    }

    void create_units(std::vector<Unit *> units, AbstractFactory *factory) {
        std::cout << "Now you can choose your warriors!\n";
        factory->message();
    }
};