#include <iostream>
#include <cstring>

class Vehicle {
protected: // дава достъп на наследниците
    char brand[10];
    double price;
    double kmPassed;
public:
    Vehicle() {
        strcpy(this->brand, "Default");
        this->price = 0;
        this->kmPassed = 0;
    }

    Vehicle(const char* brand, double price, double kmPassed) {
        strcpy(this->brand, brand);
        this->price = price;
        this->kmPassed = kmPassed;
    }

    void nullifyKm() {
        this->kmPassed = 0;
    }

    void printVehicleInfo() {
        std::cout << this->brand << std::endl;
        std::cout << this->price << std::endl;
        std::cout << this->kmPassed << std::endl;
    }
};

class Car : public Vehicle {
private:
    const int carType = 10;
public:
    Car() : Vehicle() {}

    Car(const char* brand, double price, double kmPassed) : Vehicle(brand, price, kmPassed) {}

    void printCarType() {
        std::cout << "Car type is: " << carType << std::endl << std::endl;
    }
};

// class BMW : public Car {

// };

class Bus : public Vehicle {
private:
    const int busType = 20;
public:    
    Bus() : Vehicle() {} // check how this works in header file

    Bus(const char* brand, double price, double kmPassed) : Vehicle(brand, price, kmPassed) {}

    void printBusType() {
        std::cout << "Bus type is: " << busType << std::endl; 
    }
};

int main() {
    Car c1;
    c1.printVehicleInfo();
    c1.printCarType();

    Car c2("Honda", 10000, 100);
    c2.printVehicleInfo();
    c2.printCarType();

    Bus c3("VW", 10000, 500);
    c3.printVehicleInfo();
    c3.printBusType();
}