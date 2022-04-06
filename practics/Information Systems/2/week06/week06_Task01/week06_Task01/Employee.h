#ifndef EMPLOYEEH
#define EMPLOYEEH

#include <fstream>

class Employee
{
private:
	char* name;
	int age;
	int salary;

	void copy(const Employee& other);

	void destroy();

public:

	Employee();

	Employee(const Employee& other);

	Employee& operator=(const Employee& other);

	~Employee();

	void setName(const char* name);

	void setAge(const int age);

	void setSalary(const int salary);

	char* getName() const;

	int getAge() const;

	int getSalary() const;

	void saveWorker(std::ofstream& file);
};

#endif // !EMPLOYEEH
