#ifndef PLAYER_H
#define PLAYER_H

#include <cstring>

// BIG 4 EXAMPLE

class Player {
private:
    char* name;
	int age;
	int games_played;
	int wins;
	double win_chance;
	int current_points;

    void copy(const Player& other);
    void erase();
public:
    // default constructor
    Player();
    // copy constructor
    Player(const Player& other);
    // HW: конструктор с параметри
    // оператор за присвояване
    Player& operator=(const Player& other);
    // destructor
    ~Player();

    // HW: сетъри, гетъри
};

#endif