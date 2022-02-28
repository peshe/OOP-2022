#include <iostream>

enum Subject {

    ALGEBRA,
    CALCULUS,
    DISCRETE_STRUCTURES,
    INTRO_TO_PROGRAMMING,
};

int main() {

    Subject s = Subject::ALGEBRA;
    std::cout << (s == Subject::ALGEBRA);
    return 0;
}