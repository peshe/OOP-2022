#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"

class Company {

public:
	Company(const int capacity);
	~Company();

	void addEmployee(Employee* emp);
	void removeEmployee(Employee* emp);
	void print() const;

	int getCount() const ;
	Employee** getEmployes() const;

	void sort(bool(*comparator)(const Employee*, const Employee*));

private:
	Employee** employes;
	int capacity;
	int count;

	void resize();
	void clear();
};

#endif // !COMPANY_H

