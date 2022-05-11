#include "Company.h"
#include <iostream>


Company::Company(const int capacity) {
	count = 0;
	this->capacity = capacity;
	employes = new Employee * [this->capacity];
}

Company::~Company() {
	clear();
}

void Company::addEmployee(Employee* emp) {

	if (capacity == count) {
		resize();
	}
	employes[count] = emp;
	count++;
}

void Company::removeEmployee(Employee* emp) {
	for (int i = 0; i < count; i++) {
		if (employes[i] == emp) {
			for (int j = i; j < count - 1; j++) {
				employes[j] = employes[j + 1];
			}
		}
	}

	employes[count - 1] = nullptr;
	count--;
}

int Company::getCount() const {
	return count;
}
Employee** Company::getEmployes() const {
	return employes;
}

void swap(Employee* emp1, Employee* emp2) {
	Employee temp = *emp1;
	*emp1 = *emp2;
	*emp2 = temp;
}

void Company::sort(bool(*comparator)(const Employee*, const Employee*)) {

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (comparator(employes[j], employes[j + 1])) {
				swap(employes[j], employes[j + 1]);
			}
		}
	}
}

void Company::print() const {
	std::cout << this->count;
}

void Company::resize() {
	Employee** newEmployes = new Employee * [capacity * 2];

	for (int i = 0; i < count; i++) {
		newEmployes[i] = employes[i];
	}

	clear();
	employes = newEmployes;
}

void Company::clear() {
	delete[] employes;
}