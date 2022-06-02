#pragma once
#include "hero.h"

class Warrior : public Hero {
private:
    unsigned int fury;

public:
    Warrior(const char* name = "Unknown", unsigned int hp = 120, unsigned int _fury = 0) : Hero(name, hp), fury(_fury) {

    }

    Warrior(const Warrior& other) : Hero(other) {
        fury = other.fury;
    }
    Warrior& operator=(const Warrior& other) {
        if (this != &other) {
            Hero::operator=(other);
            fury = other.fury;
        }

        return *this;
    }

    unsigned int getFury() const {
        return fury;
    }

    void attack(Hero* enemy) override {
        enemy->receiveDamage(fury + 10);
        fury += 20;
    }
    Hero* clone() const override {
        return new Warrior(*this);
    }
    void print() const override {
        Hero::print();
        std::cout << "Fury: " << fury << std::endl;
    }
};