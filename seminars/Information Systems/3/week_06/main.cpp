#include <iostream>
#include <cstring>
#include "dynamic_arr.cpp"
 
using namespace std;

class Box {
private:
    double length;
    double height;
    static int boxCount;
public:
    Box(double length, double height) {
        this->length = length;
        this->height = height;

        boxCount++;
    }

    static int getBoxCount() {
        return boxCount;
    }
};

int Box::boxCount = 0;

// -------------------------------------

void checkAge(int age) {
    if (age >= 18) {
        std::cout << "Access granted - you are old enough!" << std::endl;
    } else {
        throw(age);
    }
}

int main() {
    std::cout << Box::getBoxCount() << std::endl;
    Box b1(5, 6);
    Box b2(1, 7);
    Box b3(22, 4);
    std::cout << Box::getBoxCount() << std::endl;

    try {
        int age = 15;
        checkAge(age);
    } catch (int num) {
        // handle error
        std::cout << "Access denied!" << std::endl;
        std::cout << "Age is: " << num;
    }

    // ----------
    // DYNAMIC ARRAY 

    std::cout << std::endl;
    DynamicArray* arr = new DynamicArray();
    arr->push_back(1);
    arr->push_back(15);
    arr->push_back(6432);
    arr->push_back(11);
    arr->push_back(51);
    arr->push_back(1);
    arr->print();
}