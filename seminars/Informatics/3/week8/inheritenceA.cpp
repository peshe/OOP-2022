#include <iostream>
#include <string>

class Person {
public:
    std::string name;
};

class Employee: public Person {
public:
    std::string company;
    
    void print() {
        std::cout<< name<< " works for "<< company;
    }
};

class Developer: public Employee {
public:
    void print() {
        Employee::print();
        std::cout<< " as a developer";
    }
};

class Manager: public Employee {
public:
    void print() {
        Employee::print();
        std::cout<< " as a manager";
    }
};

int main() {
    Employee e;
    e.name = "Sasho";
    e.company = "Tesla";
    e.print();
    std::cout<< std::endl;
    
    Manager m;
    m.name = "Elton";
    m.company = "Ministerstvoto na otbranata";
    m.print();
    std::cout<< std::endl;
}