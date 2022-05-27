// Week09_task0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*
* Да се напише програма, която описва устройство 
по следните характеристики - памет, скорост и брой ядра. 
Представете устройството телефон и устройството лаптоп с основните характеристики. 
За устройството телефон добавете размер на екран, а за устройството лаптоп резолюция на екран. 
Напишете методи, които връщат информация за характеристиките на телефон и лаптоп.
*/

class Device {
private:
    int* arr;
    unsigned memory;
    unsigned speed;
    unsigned threads;

public:
    Device() {
        memory = 0;
        speed = 0;
        threads = 0;
    }

    Device(const unsigned& _memory, const unsigned& _speed, const unsigned& _threads) {
        memory = _memory;
        speed = _speed;
        threads = _threads;
    }

    void printDeviceInfo() const {
        std::cout << memory << " " << speed << " " << threads << std::endl;
    }
};

class Phone : public Device {
private:
    unsigned screenSize;

public:
    Phone() : Device() {
        screenSize = 0;
    }

    Phone(const unsigned& memory, const unsigned& _speed, const unsigned& _threads, const unsigned& _screenSize) : Device(memory, _speed, _threads) {
        screenSize = _screenSize;
    }

    void printPhoneInfo() const {
        this->printDeviceInfo();
        std::cout << screenSize << std::endl;
    }
};

class Laptop : public Device {
private:
    unsigned screenResolution;

public:
    Laptop() : Device() {
        screenResolution = 0;
    }

    Laptop(const unsigned& memory, const unsigned& _speed, const unsigned& _threads, const unsigned& _screenResolution) : Device(memory, _speed, _threads) {
        screenResolution = _screenResolution;
    }

    void printLaptopInfo() const {
        this->printDeviceInfo();
        std::cout << screenResolution << std::endl;
    }
};

int main()
{
    Device d;
    Phone p;
    Laptop l;

    d.printDeviceInfo();

    p.printDeviceInfo();
    p.printPhoneInfo();

    l.printDeviceInfo();
    l.printLaptopInfo();

    return 0;
}