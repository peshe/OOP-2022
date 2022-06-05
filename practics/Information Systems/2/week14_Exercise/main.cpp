#include <iostream>

#include "Component.h"
#include "Memory.h"
#include "Processor.h"
#include "Config.hpp"

Component* create_component() {
	std::string component;

	std::cout << "Enter desired component\n";

	std::cin >> component;

	if (component == "Memory") {
		
		return new Memory(std::cin);
		
	}
	else if (component == "Processor") {
		
		return new Processor(std::cin);
	}

	return nullptr;
}

int main()
{
	Component* c;

	try {
		c = create_component();
	} catch (std::exception& e) {
		std::cout << e.what();
	} 

	Memory mem("Samsung", 4);
	Processor p("Samsung", 6, 1800);

	Config config;

	config.add(mem);
	config.add(p);
	config.add(mem);
	config.add(*c);

	config.remove(mem);

	config.print();

	delete c;
	
}