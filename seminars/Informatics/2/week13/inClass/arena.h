#pragma once
#include "magician.h"
#include "warrior.h"
#include <iostream>

class Arena {
private:
    size_t numberOfHeroes;
    size_t capacity;
    Hero** heroes; //Hero* heroes[10]

private:
    void destroy() {
        for (unsigned int i = 0; i < numberOfHeroes; ++i) {
            delete heroes[i];
        }
        delete[] heroes;
    }

public:
    Arena() = delete;
    Arena(Hero** _heroes, size_t number) {
        capacity = number * 2;
        heroes = new Hero*[capacity];
        numberOfHeroes = number;
        for (unsigned int i = 0; i < numberOfHeroes; ++i) {
            heroes[i] = _heroes[i]->clone(); //copy _heroes[0], heroes[0] -> copy _heroes[0]
        }
    }
    Arena(const Arena& other) = delete;
    Arena& operator=(const Arena& other) = delete;
    ~Arena() {
        destroy();
    }

    void showInfo() const {
        for (unsigned int i = 0; i < numberOfHeroes; ++i) {
            heroes[i]->print();
            std::cout << "-----------------------\n";
        }
        std::cout << std::endl;
    }

    void removeDeath() {
        for (unsigned int i = 0; i < numberOfHeroes; ++i) {
            if (heroes[i]->getHp() == 0) {
                for (unsigned int j = i; j < numberOfHeroes; ++j) {
                    heroes[j] = heroes[j + 1];
                }
            }
        }
        --numberOfHeroes;
    }

    void round() {
        for (unsigned int i = 0; i < numberOfHeroes; ++i) {
            for (unsigned int j = 0; j < numberOfHeroes; ++j) {
                if (i != j) {
                    heroes[i]->attack(heroes[j]);
                }
            }
        }
        showInfo();
        removeDeath();
    }

    void fight() {
        while (numberOfHeroes > 1) {
            round();
        }
        
        try {
            std::cout << "Winner: ";
            heroes[0]->print();
        } catch (...) {
            std::cout << "No winner\n";
        }
    }
};