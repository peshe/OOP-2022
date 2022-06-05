#pragma once
#include "Component.h"

class Memory : public Component
{
private:
	unsigned short capacity;

	void setCapacity(unsigned short capacity);
public:

	Memory() = default;

	Memory(std::istream& is);

	Memory(const std::istream& is);

	Memory(const std::string& label, const unsigned short capacity);

	Memory(const Memory& other) = default;

	//~Memory();

	Component* clone() const;

	Memory& operator=(const Memory& other) = delete;

	double price() const override;

	void output(std::ostream& out) const override;

	unsigned short getCapacity() const;

	bool operator==(const Component& obj) const;
};