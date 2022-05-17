#include <iostream>

class A {
protected:
int x;
public:
    A() {
        x = 5;
        std::cout<< "A constructed"<< std::endl;
    }
    
    ~A() {
        std::cout<< "A destroyed"<< std::endl;
    }
};
class B: public A {
int y;
public:
    B() {
        y = x*x;
        std::cout<< "B constructed"<< std::endl;
    }
    
    ~B() {
        std::cout<< "B destroyed"<< std::endl;
    }
};

int main() {
    B b;
    
    return 0;
}