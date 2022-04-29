#include <iostream>

class A {
public:
    int a;
    int b;
    explicit A(int a, int b = 15) : a(a), b(b) {}
};

void print(A a) { std::cout<< a.a<< " " << a.b<< std::endl; }

int main() {
    print(5);
}