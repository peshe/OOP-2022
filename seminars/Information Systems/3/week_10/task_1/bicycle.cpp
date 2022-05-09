#include "bicycle.h"

Bycicle::Bycicle() {
    this->hasLights = false;
    this->hasRing = false;
    this->speeds = 0;
}

void Bycicle::copy(const Bycicle& other) {
    Vehicle::operator=(other);
    this->hasLights = other.hasLights;
    this->hasRing = other.hasRing;
    this->speeds = other.speeds;
}

Bycicle::Bycicle(const char* color, const char* brand, int year, int seats,
                double maxVelocity, bool hasLights, bool hasRing, int speeds) 
: Vehicle(color, brand, year, seats, maxVelocity) {
    this->hasLights = hasLights;
    this->hasRing = hasRing;
    this->speeds = speeds;
}

Bycicle::Bycicle(const Bycicle& other) {
    this->copy(other);
}

Bycicle& Bycicle::operator=(const Bycicle& other) {
    if (this != &other) {
        this->copy(other);
    }

    return *this;
}

void Bycicle::print() const {
    Vehicle::print();
    std::cout << "Has lights: " << this->hasLights << std::endl;
    std::cout << "Has ring: " << this->hasRing << std::endl;
    std::cout << "Number of speeds: " << this->speeds << std::endl;
}