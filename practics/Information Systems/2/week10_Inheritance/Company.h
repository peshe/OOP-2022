#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"

class Company {

public:
	Company(const int capacity);
	~Company();

	void addEmployee(const Employee& emp);
	void removeEmployee(const Employee& emp);
	void print() const;

	int getCount() const ;
	const Employee* const * getEmployes() const;

	void sort(bool(*comparator)(const Employee*, const Employee*));

private:
	Employee** employes;
	int capacity;
	int count;

	void resize();
	void clear();
};

#endif // !COMPANY_H

