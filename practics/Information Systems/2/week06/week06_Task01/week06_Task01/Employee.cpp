#include "Employee.h"
#include <cstring>

#pragma warning(disable : 4996) // for strcpy()

void Employee::copy(const Employee& other)
{
	setName(other.name);
	setAge(other.age);
	setSalary(other.salary);
}

void Employee::destroy()
{
	delete[] name;
}

Employee::Employee()
{
	this->name = nullptr;
	this->age = 0;
	this->salary = 0;
}

Employee::Employee(const Employee& other)
{
	copy(other);
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Employee::~Employee()
{
	destroy();
}

void Employee::setName(const char* name)
{
	if (name != nullptr)
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
		}

		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

void Employee::setAge(const int age)
{
	if (age > 0)
	{
		this->age = age;
	}
}

void Employee::setSalary(const int salary)
{
	if (salary > 0)
	{
		this->salary = salary;
	}
}

char* Employee::getName() const
{
	return name;
}

int Employee::getAge() const
{
	return age;
}

int Employee::getSalary() const
{
	return salary;
}

void Employee::saveWorker(std::ofstream& file)
{
	file << name;
	file << age;
	file << salary;
}