#pragma once
#include "hero.h"

class Magician : public Hero {
private:
    unsigned int mana;

public:
    // Magician() : Hero("Unknown", 100) {
    //     mana = 200;
    // }
    // Magician() : Magician("Unknown", 100, 200) {}
    Magician(const char* name = "Unknown", unsigned int hp = 100, unsigned int _mana = 200) : Hero(name, hp), mana(_mana) {

    }
    Magician(const Magician& other) : Hero(other) {
        mana = other.mana;
    }
    Magician& operator=(const Magician& other) {
        if (this != &other) {
            Hero::operator=(other);
            mana = other.mana;
        }

        return *this;
    }
    

    unsigned int getMana() const {
        return mana;
    }

    
    void attack(Hero* enemy) override {
        enemy->receiveDamage(mana);
        mana -= 20;
    }
    Hero* clone() const override {
        return new Magician(*this);
    }
    void print() const override {
        Hero::print();
        std::cout << "Mana: " << mana << std::endl;
    }
};