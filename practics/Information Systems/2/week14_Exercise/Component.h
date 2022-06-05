#pragma once
#include <iostream>
#include <string>
#include <typeinfo>

class Component
{
protected:
	std::string label;

	Component() {}

	Component(std::istream& is);
public:

	Component(const std::string& label)/* : label(label) */
	{
		this->label = label;
	}

	virtual double price() const = 0;

	virtual void output(std::ostream& out) const = 0;

	virtual Component* clone() const = 0;

	virtual bool operator==(const Component& obj) const {
		
		if (typeid(*this) != typeid(obj) || this->label != obj.label)	return false;
		

		return true;
	}

	//virtual ~Component() {}
};