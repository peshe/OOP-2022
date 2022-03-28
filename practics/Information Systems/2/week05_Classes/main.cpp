#include <iostream>
#include "Rational.hpp"

int main() {

    Rational res = Rational(1, 2).divide(Rational(4, 6));
    res.print();
    return 0;
}