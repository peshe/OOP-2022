#include "Developer.h"

Developer::Developer(const char* name, const unsigned int months, bool knowCPlusPlus, bool knowCSharp) {
	setName(name);
	setMonths(months);
	this->knowCPlusPlus = knowCPlusPlus;
	this->knowCSharp = knowCSharp;
}

Developer::Developer(const Developer &obj) 
: Employee::Employee(obj),
  knowCPlusPlus(obj.knowCPlusPlus), 
  knowCSharp(obj.knowCSharp) 
  
{
	
}

Developer& Developer::operator=(const Developer& obj) {

	if (this != &obj) {
		Employee::operator=(obj);

		this->knowCSharp = obj.knowCSharp;
		this->knowCPlusPlus = obj.knowCPlusPlus;
	}
	return *this;
}

Developer& Developer::operator=(Developer&& obj) {

	if (this != &obj) {
		Employee::operator=(obj);

		this->knowCSharp = obj.knowCSharp;
		this->knowCPlusPlus = obj.knowCPlusPlus;
	}
	return *this;
}

Developer::~Developer() {}

bool Developer::operator==(const Employee &rhs) const
{
    std::cout << "derived dev == call\n";

    if (!Employee::operator==(rhs)) return false;
    
    const Developer* dev = dynamic_cast<const Developer*>(&rhs);
    
    return this->knowCPlusPlus == dev->knowCPlusPlus && this->knowCSharp == dev->knowCSharp;
}

Employee* Developer::clone() const {
	
	return new Developer(*this);
}
