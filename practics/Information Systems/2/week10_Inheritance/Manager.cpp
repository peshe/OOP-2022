#include "Manager.h"

Manager::Manager(const char* name, const unsigned int months, unsigned int countEmployees) {
	setName(name);
	setMonths(months);
	this->countEmployees = countEmployees;
}

Manager::Manager(const Manager& obj) : Employee::Employee(obj), countEmployees(obj.countEmployees) {}

Manager& Manager::operator=(const Manager& obj) {

	if (this != &obj) {

		Employee::operator=(obj);
		this->countEmployees = obj.countEmployees;
	}

	return *this;
}

Manager& Manager::operator=(Manager&& obj) {
	if (this != &obj) {

		this->name = obj.name;
		obj.name = nullptr;

		this->months = obj.months;
		this->countEmployees = obj.countEmployees;
	}

	return *this;
}

Manager::~Manager() {
	
}

bool Manager::operator==(const Employee& rhs) const
{
    std::cout << "derived mgr == call\n";

    if (!Employee::operator==(rhs)) return false;

    const Manager *mgr = dynamic_cast<const Manager*>(&rhs);

    return this->countEmployees == mgr->countEmployees;
}

Employee* Manager::clone() const {

	return new Manager(*this);
}
