#ifndef __VEHICLE_H
#define __VEHICLE_H

#include <iostream>
#include <cstring>

class Vehicle {
protected:
    char* color;
    char* brand;
    int year;
    int seats;
    double maxVelocity;
private:
    void copy(const Vehicle&);
    void erase();
public:
    Vehicle();
    Vehicle(const Vehicle&);
    Vehicle(const char* color, const char* brand, size_t year, size_t seats, double maxVelocity);
    Vehicle& operator=(const Vehicle&);
    ~Vehicle();

    void print() const;
};

#endif