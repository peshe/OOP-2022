#pragma once
#include <cstring>
#include <iostream>

class Hero {
private:
    unsigned int hp;
    char* name;

public:
    Hero() {
        hp = 0;
        name = new char[8];
        strcpy(name, "Unknown");
    }
    Hero(const char* _name, unsigned int _hp) {
        
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        hp = _hp;
    }
    Hero(const Hero& other) {
        // std::cout << "copy hero\n";
        this->name = new char[std::strlen(other.name) + 1];
        std::strcpy(this->name, other.name);
        this->hp = other.hp;
    }
    Hero& operator=(const Hero& other) {
        if (this != &other) {
            delete[] name;
            this->name = new char[std::strlen(other.name) + 1];
            std::strcpy(this->name, other.name);
            this->hp = other.hp;
        }
        // std::cout << "operator= hero\n";

        return *this;
    }
    virtual ~Hero() {
        delete[] name;
    }

    void receiveDamage(unsigned int damage) {
        hp = hp <= damage ? 0 : (hp - damage);
    } 

    unsigned int getHp() const {
        return hp;
    }
    const char* getName() const {
        return name;
    }

    // virtual unsigned int getDamage() const = 0;
    virtual void attack(Hero* enemy) = 0;
    virtual Hero* clone() const = 0;
    virtual void print() const {
        std::cout << "Hero: " << name << "\nHealth: " << hp << std::endl;
    }
};