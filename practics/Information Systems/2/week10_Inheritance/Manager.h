#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
public:
	Manager(const char* name, const unsigned int months, unsigned int countEmployees);
	Manager(const Manager& obj);
	Manager& operator=(const Manager& obj);
	Manager& operator=(Manager&& obj);

	~Manager();

	bool operator==(const Employee& rhs) const;

	Employee* clone() const;
private:
	unsigned int countEmployees;

};

#endif // !MANAGER_H
