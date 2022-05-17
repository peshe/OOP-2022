#include <iostream>

class Base {
private:
	void callPrivate() { std::cout << "basePrivate\n"; }
protected:
	void callProtected() { std::cout << "baseProtected\n"; }
public:
	virtual void callPublic() const = 0;
};
class Derived: public Base {
private:
	static int n;
	void callPrivate() { std::cout << "derivedPrivate\n"; }
protected:
	void callProtected() { std::cout << "derivedProtected\n"; }
public:
	void callPublic() const override { std::cout << "derivedPublic\n"; }
public:
	Derived() {  }
	static Derived* make() {
	/*	this->n;
		Derived::n;*/
		return new Derived();
	}
	void callMake() {
		Derived::make();
		this->n = 5;
	}
};



class Employee {
	char name[30];
	char egn[11];
	double salary;
public:
	Employee(const char* name = "", double salary = 0) {
		strcpy_s(this->name, strlen(name) + 1, name);
		this->salary = salary;
	}
	void work() {
		std::cout << name << " is working\n";
	}
};


class Employable {
public:
	virtual void work() = 0;
};

class Dog : public Employable {
	void work() override {

	}
};

class Company {
	Employable** employees;
	std::size_t size, capacity;
public:
	Company() {
		capacity = 8;
		size = 0;
		employees = new Employable*[capacity];
	}
	void work() {
		for (size_t i = 0; i < size; ++i) {
			employees[i]->work();
		}
	}
	Company& addEmployee(Employable* newEmployee) {
		if (size == capacity) {
			// resize();
		}
		this->employees[size] = newEmployee;
		++size;
		return *this;
	}
};




int main() {
	Employee gosho("Gosho"), pesho("Pesho");
	Company c;
	c.addEmployee(gosho).addEmployee(pesho);
	c.work();
	return 0;
}










