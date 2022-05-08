#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
public:
	Manager(const char* name, const unsigned int months, unsigned int countEmployees);

private:
	unsigned int countEmployees;

};

#endif // !MANAGER_H
