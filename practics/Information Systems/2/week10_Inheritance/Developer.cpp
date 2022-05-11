#include "Developer.h"

Developer::Developer(const char* name, const unsigned int months, bool knowCPlusPlus, bool knowCSharp) {
	setName(name);
	setMonths(months);
	this->knowCPlusPlus = knowCPlusPlus;
	this->knowCSharp = knowCSharp;
}
