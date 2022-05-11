#include <iostream>

class A {
public:
    void print() { std::cout<< "adsf"; }
};
class B {
public:
    void print() { std::cout<< "vsd"; }
};
class C: public A, public B {
public:
    void print() { A::print(); }
};

int main() {
    C c;
    c.print();
    
    return 0;
}