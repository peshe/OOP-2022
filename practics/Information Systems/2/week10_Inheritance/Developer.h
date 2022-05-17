#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee { 
	
public:
	Developer(const char* name, const unsigned int months, bool knowCPlusPlus, bool knowCSharp);
	Developer(const Developer& obj);
	Developer& operator=(const Developer& obj);
	Developer& operator=(Developer&& obj);
	~Developer();

	bool operator==(const Employee& rhs) const;

    //bool operator!=(const Developer &rhs) const;

	Employee* clone() const;

private:
	bool knowCPlusPlus;
	bool knowCSharp;
};

#endif // !DEVELOPER_h

