#include <iostream>

class A {
public: 
    int a;
    static int aCount;
    
    A(int a): a(a) {
        aCount +=1;
    }
};

int A::aCount = 0;

int main() {
    A a1(5);
    A a2(6);
    std::cout<< A::aCount;
}