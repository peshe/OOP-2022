#include "Memory.h"
#include <exception>

void Memory::setCapacity(unsigned short capacity)
{
	if (capacity < 1 || capacity > 10000)
	{
		throw std::invalid_argument("Invalid capacity!");
	}

	this->capacity = capacity;
}

Memory::Memory(const std::string& label, const unsigned short capacity)
	: Component(label)
{
	setCapacity(capacity);
}

Memory::Memory(std::istream& is) {
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	std::getline(is, this->label);

	unsigned short capacity;

	std::cin >> capacity;

	this->setCapacity(capacity);
}

double Memory::price() const
{
	return this->capacity * 89.99;
}

void Memory::output(std::ostream& out) const
{
	if (out)
	{
		out << this->label << std::endl;
		out << this->capacity << std::endl;
		out << this->price() << std::endl;
	}
}

Component* Memory::clone() const {
	return new Memory(*this);
}

unsigned short Memory::getCapacity() const
{
	return this->capacity;
}

bool Memory::operator==(const Component& obj) const {

	std::cout << "derived == memory\n\n";

	if (!Component::operator==(obj)) return false;

	const Memory &ref = dynamic_cast<const Memory&>(obj);

	return this->capacity == ref.capacity;
}