#include <iostream>
#include "magician.h"
#include "warrior.h"
#include "arena.h"
#include <iostream>

int main() {
    Magician m("Magician", 500, 150);
    Warrior w("Warrior", 750, 20);

    // std::cout << m.getMana() << std::endl;
    // std::cout << w.getFury() << std::endl;

    Magician m2 = m;
    // std::cout << m2.getMana() << std::endl;
    Magician m3;
    m2 = m3;
    // std::cout << m2.getMana() << std::endl;

    Hero** heroes = new Hero*[4];
    heroes[0] = &m;
    heroes[1] = &w;
    heroes[2] = &m2;
    heroes[3] = &m3;

    Arena arena(heroes, 4);
    arena.showInfo();
    arena.fight();
    arena.showInfo();

    return 0;
}