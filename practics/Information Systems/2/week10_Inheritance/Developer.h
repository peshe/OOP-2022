#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee { 
	
public:
	Developer(const char* name, const unsigned int months, bool knowCPlusPlus, bool knowCSharp);

private:
	bool knowCPlusPlus;
	bool knowCSharp;
};

#endif // !DEVELOPER_h

