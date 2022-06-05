#pragma once
#include <string>
#include "Component.h"

class Processor : public Component
{
private:
	unsigned short cores;
	unsigned short clockSpeed;

	void setCores(unsigned short cores);

	void setClockSpeed(unsigned short clockSpeed);

public:

	Processor() = default;

	Processor(std::istream& is);

	Processor(const std::string& label, const unsigned short cores, const unsigned short clockSpeed);

	Processor(const Processor& other) = default;

	Processor& operator=(const Processor& other) = delete;

	Component* clone() const override;

	//virtual ~Processor();

	double price() const override;

	void output(std::ostream& out) const override;

	unsigned short getCores() const;

	unsigned short getClockSpeed() const;

	bool operator==(const Component& obj) const;
};