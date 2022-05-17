#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <typeinfo>
#include <iostream>
#include <cstring>

class Employee {

public:
	Employee();
	Employee(const char* name, const unsigned int month);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	Employee& operator=(Employee&& obj);
	
	virtual ~Employee();

	virtual bool operator==(const Employee& rhs) const;

    bool operator!=(const Employee &rhs) const;

	void setName(const char* name);
	void setMonths(const unsigned int months);

	const char* getName() const;
	unsigned int getMonths() const;

	virtual Employee* clone() const = 0;

protected:
	char* name;
	unsigned int months;

private:
	void copy(const Employee& other);
	void clear();
};

#endif // !EMPLOYEE_H
