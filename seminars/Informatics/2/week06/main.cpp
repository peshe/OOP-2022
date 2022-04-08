#include <iostream>
#include <cassert>
#include "./Array.h"

int main() {
    Array traicho;
    traicho.pushBack(10);
    traicho.pushBack(2);
    // traicho.print();
    assert(traicho.getSize() == 2);
    assert(traicho.getAtPosition(1) == 2);

    // pencho = traicho;
    /*
    for (std::size_t i = 0; i < pencho.getSize(); i++) {
        std::cout << pencho.getAtPosition(i) << " ";
    }
    std::cout << '\n';
    traicho.setAtPosition(2, 300);
    std::cout << pencho.getAtPosition(2) << " ";

    pencho = marijka;
    */
}

