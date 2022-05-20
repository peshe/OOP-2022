#include <iostream>
#include <cstring>
#include <typeinfo>

class Test {
private:
    int a;
public:
    Test(int _a) : a(_a) {}
};

template <typename T>
T add(T a, T b) {
    return a + b;   
}

template <typename T>
T bigger(T a, T b) {
    return (a > b ? a : b);   
}

template <typename T, typename S>
void print_pair(T firstType, S secondType) {
    std::cout << firstType << " and type is: " << typeid(firstType).name() << std::endl;
	std::cout << secondType << " and type is: " << typeid(secondType).name() << std::endl;
}

int main() {
    double doubleValue = add(5.14,2.3);
    int intValue = add(5, 33);
    std::cout << doubleValue << std::endl;

    print_pair(doubleValue, doubleValue);
}