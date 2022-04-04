#include <iostream>
#include <fstream>
#include "Company.h"

void Company::copy(const Company& other)
{
	this->workers = new Employee[other.count];

	for (int i = 0; i < other.count; i++)
	{
		this->workers[i] = other.workers[i];
	}

	this->count = other.count;
}

void Company::resize()
{
	this->capacity *= 2;
	Employee* temp = new Employee[this->capacity];

	for (int i = 0; i < this->count; i++)
	{
		temp[i] = this->workers[i];
	}

	delete[] this->workers;
	this->workers = temp;
}

void Company::destroy()
{
	delete[] workers;
}

Company::Company()
{
	this->workers = nullptr;
	this->capacity = 0;
	this->count = 0;
}

Company::Company(const int capacity)
{
	this->workers = new Employee[capacity];
	this->count = 0;
	this->capacity = capacity;
}

Company::Company(const Company& other)
{
	copy(other);
}

Company& Company::operator=(const Company& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Company::~Company()
{
	destroy();
}

void Company::addEmployee(const Employee& newEmployee)
{
	if (this->workers == nullptr)
	{
		this->workers = new Employee[8];
		this->capacity = 8;
	}
	if (this->count + 1 == this->capacity)
	{
		resize();
	}

	this->workers[this->count++] = newEmployee;
}

const Employee& Company::getMostPaid() const
{
	int maxSalary = INT_MIN;//for INT_MAX include <iostream>
	int index = -1;

	for (int i = 0; i < this->count; i++)
	{
		if (this->workers[i].getSalary() > maxSalary)
		{
			maxSalary = this->workers[i].getSalary();
			index = i;
		}
	}

	return this->workers[index];
}

void Company::saveWorkers(const char* fileName)
{
	std::ofstream myFile(fileName, std::ios::app | std::ios::trunc);
	myFile << this->count;
	myFile << this->capacity;

	for (int i = 0; i < this->count; i++)
	{
		this->workers[i].saveWorker(myFile);
	}

	myFile.close();
}