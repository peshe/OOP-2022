#include "vehicle.h"

void Vehicle::copy(const Vehicle& other) {
    this->color = new char[strlen(other.color) + 1];
    strcpy(this->color, other.color);
    this->brand = new char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);

    this->year = other.year;
    this->seats = other.seats;
    this->maxVelocity = other.maxVelocity;
}

void Vehicle::erase() {
    delete[] this->color;
    delete[] this->brand;
}

Vehicle::Vehicle() {
    this->color = new char[1];
    this->color[0] = '\0';

    this->brand = new char[1];
    this->brand[0] = '\0';
    
    this->year = 1970;
    this->seats = 0;
    this->maxVelocity = 0;
}

Vehicle::Vehicle(const char* color, const char* brand, size_t year, size_t seats, double maxVelocity) {
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);

    this->year = year;
    this->seats = seats;
    this->maxVelocity = maxVelocity;
}

Vehicle::Vehicle(const Vehicle& other) {
    this->copy(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        this->erase();
        this->copy(other);
    }

    return *this;
}

Vehicle::~Vehicle() {
    this->erase();
    std::cout << "Deleted from Vehicle destructor" << std::endl;
}

void Vehicle::print() const
{
	std::cout << "Color: " << this->color << std::endl;
    std::cout << "Brand: " << this->brand << std::endl;
    std::cout << "Year: " << this->year << std::endl;
    std::cout << "Number of seats: " << this-> seats << std::endl;
    std::cout << "Max speed: " << this->maxVelocity << std::endl;
}
