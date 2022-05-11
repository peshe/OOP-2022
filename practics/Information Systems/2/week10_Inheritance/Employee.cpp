#include "Employee.h"
#include <cstring>

Employee::Employee() : name(nullptr), months(0) { }

Employee::Employee(const char* name, const unsigned int month) {
	
	setName(name);
	setMonths(month);
}

Employee::Employee(const Employee& other) {
	copy(other);
}

Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		clear();
		copy(other);
	}

	return *this;
}

Employee& Employee::operator=(Employee&& obj) {

	if (this != &obj) {
		this->name = obj.name;
		obj.name = nullptr;

		this->months = obj.months;
	}
	return *this;
}

Employee::~Employee() {
	clear();
}

bool Employee::operator==(const Employee& rhs) const
{
    //std::cout << "typeid check " << (typeid(*this)== typeid(rhs)) << '\n';

    return typeid(*this)== typeid(rhs) && strcmp(name, rhs.name) == 0 && months == rhs.months;
}

bool Employee::operator!=(const Employee &rhs) const
{
    return !(rhs == *this);
}


void Employee::setName(const char* name) {
	
	int size = strlen(name) + 1;
	if (this->name != nullptr) {
		delete[] name;
	}

	this->name = new char[size];
	strcpy(this->name, name);
}

void Employee::setMonths(const unsigned int months) {
	this->months = months;
}

unsigned int Employee::getMonths() const {
	return months;
}

const char* Employee::getName() const {
	return name;
}

void Employee::copy(const Employee& other) {
	setName(other.name);
	setMonths(other.months);
}

void Employee::clear() {
	delete[] name;
}