#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {

public:
	Employee();
	Employee(const char* name, const unsigned int month);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	~Employee();

	void setName(const char* name);
	void setMonths(const unsigned int months);

	char* getName() const;
	unsigned int getMonths() const;

protected:
	char* name;
	unsigned int months;

private:
	void copy(const Employee& other);
	void clear();
};

#endif // !EMPLOYEE_H
