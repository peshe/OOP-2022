#ifndef COMPANYH
#define COMPANYH

#include "Employee.h"

class Company
{
private:
	Employee* workers;
	int capacity;
	int count;

	void copy(const Company& other);

	void resize();

	void destroy();

public:

	Company();

	Company(const int capacity);

	Company(const Company& other);

	Company& operator=(const Company& other);

	~Company();

	void addEmployee(const Employee& newEmployee);

	const Employee& getMostPaid() const;

	void saveWorkers(const char* fileName);
};

#endif // !COMPANYH
