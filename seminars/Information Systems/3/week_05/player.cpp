#include "player.h"

// BIG 4 EXAMPLE

void Player::copy(const Player& other) {
    this->name = new char[strlen(other.name) + 1]; // 1) заделяане на памет
    strcpy(this->name, other.name); // 2) присвояване на масива
    this->age = other.age;
    this->wins = other.wins;
    this->games_played = other.games_played;
    this->win_chance = other.win_chance;
    this->current_points = other.current_points;
}

void Player::erase() {
    delete[] this->name;
}

// default constructor
Player::Player() {
    this->name = new char[1];
    this->name[0] = '\0'; 
    this->age = 0;
    this->games_played = 0;
    this->wins = 0;
    this->win_chance = 0;
    this->current_points = 0;
}

// copy constructor
Player::Player(const Player& other) {
    this->copy(other);
}

// оператор за присвояване
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        this->erase();
        this->copy(other);
    }
    
    return *this;
}

// destructor
Player::~Player() {
    this->erase();
}