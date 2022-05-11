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

Employee::~Employee() {
	clear();
}

void Employee::setName(const char* name) {
	
	int size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}

void Employee::setMonths(const unsigned int months) {
	this->months = months;
}

unsigned int Employee::getMonths() const {
	return months;
}

char* Employee::getName() const {
	return name;
}

void Employee::copy(const Employee& other) {
	setName(other.name);
	setMonths(other.months);
}

void Employee::clear() {
	delete[] name;
}