#include "Processor.h"
#include <exception>

Processor::Processor(std::istream& is) {
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	std::getline(is, this->label);

	unsigned short cores, speed;

	std::cin >> cores;
	std::cin >> speed;

	this->setClockSpeed(speed);
	this->setCores(cores);

	
}

//Processor::~Processor() {}

void Processor::setCores(unsigned short cores)
{
	if (cores < 1 || cores > 8)
	{
		throw std::invalid_argument("Invalid number cores!");
	}

	this->cores = cores;
}

Component* Processor::clone() const {
	return new Processor(*this);
}

void Processor::setClockSpeed(unsigned short clockSpeed)
{
	this->clockSpeed = clockSpeed;
}

Processor::Processor(const std::string& label, const unsigned short cores, const unsigned short clockSpeed)
	: Component(label)
{
	setCores(cores);
	setClockSpeed(clockSpeed);
}

double Processor::price() const
{
	return this->cores * 29.99;
}

void Processor::output(std::ostream& out) const
{
	if (out)
	{
		out << this->label << std::endl;
		out << this->cores << std::endl;
		out << this->clockSpeed << std::endl;
		out << this->price() << std::endl;
	}
}

unsigned short Processor::getCores() const
{
	return this->cores;
}

unsigned short Processor::getClockSpeed() const
{
	return this->clockSpeed;
}

bool Processor::operator==(const Component& obj) const {

	if (!Component::operator==(obj)) return false;

	const Processor &ref = dynamic_cast<const Processor&>(obj);

	return this->clockSpeed == ref.clockSpeed && this->cores == ref.cores;

}