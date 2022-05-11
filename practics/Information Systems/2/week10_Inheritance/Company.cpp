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

void Company::addEmployee(const Employee& emp) {

	if (capacity == count) {
		resize();
	}
	employes[count] = emp.clone();
	count++;
}

void Company::removeEmployee(const Employee& emp) {
	for (int i = 0; i < count; i++) {
		std::cout << employes[i]->getName() << ' ';
		if (*employes[i] == emp) {
			
			delete employes[i];

			for (int j = i; j < count - 1; j++) {
				employes[j] = employes[j + 1];
			}
			--i;
			--count;
			employes[count] = nullptr;
		}
	}

}

int Company::getCount() const {
	return count;
}
const Employee* const * Company::getEmployes() const {
	return employes;
}

void swap(Employee*& emp1, Employee*& emp2) {
	Employee *temp = emp1;
	emp1 = emp2;
	emp2 = temp;
}

void Company::sort(bool(*comparator)(const Employee*, const Employee*)) {

	for (int i = 1; i < count; i++) {
		for (int j = 0; j < i; j++) {

			if (comparator(employes[j], employes[i])) {
				swap(employes[j], employes[i]);
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

	delete employes;
	employes = newEmployes;
}

void Company::clear() {
	
	for (int i = 0; i < this->count; ++i) {
		delete employes[i];
	}

	delete[] employes;
}