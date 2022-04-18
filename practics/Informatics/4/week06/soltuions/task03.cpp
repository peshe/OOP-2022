#include <iostream>
#include <fstream>
#include <cstring>

class Employee
{
private:
    char* name;
    int years;
    double salary;

public:
    void set_name(const char* name)
    {
        if (name == nullptr)
        {
            throw "Invalid word!";
        }
    
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    }

    const char* get_name() const
    {
        return this->name;
    }

    void set_years(const int years)
    {
        if(years < 0)
        {
            this->years = 0;
        }
        this->years = years;
    }

    int get_years() const
    {
        return this->years;
    }
    
    void set_salary(const double salary)
    {
        if (salary < 0)
        {
            this->salary = 0;
        }
        this->salary = salary;
    }

    int get_salary() const
    {
        return this->salary;
    }

    Employee()
    {
        this->name = nullptr;
        this->years = 0;
        this->salary = 0;
    }

    Employee(const Employee& other)
        : years(other.years), salary(other.salary)
    {
        this->set_name(other.name);
    }

    Employee& operator=(const Employee& other)
    {
        if(this != &other)
        {
            delete[] name;
            this->set_name(other.name);
            this->set_salary(other.salary);
            this->set_years(other.years);
        }

        return *this;
    }

    ~Employee()
    {
        delete[] this->name;
    }
};

class Company
{
private:
    Employee* employees;
    int size;

public:
    Company()
    {
        this->employees = 0; 
        this->size = 0;
    }

    ~Company()
    {
        delete[] this->employees;
    }

    void add_employee(const Employee& new_employee)
    {
        Employee* tmp = new Employee[size + 1];
        for(int i = 0; i < size; i++)
        {
            tmp[i] = employees[i];
        }
        tmp[size] = new_employee;
        
        if(this->employees != nullptr)
        {
            delete[] this->employees;
        }
        this->employees = tmp;
        ++size;
    }

    Employee& get_most_paid() const
    {
        int max_salary = employees[0].get_salary();
        int wanted_employee = 0;
        
        for(int i = 1; i < size; i++)
        {
            if(employees[i].get_salary() > max_salary)
            {
                max_salary = employees[i].get_salary();
                wanted_employee = i;
            }
        }
        
        return employees[wanted_employee];
    }

    void save_to_file(const char* file_name)
    {
        std::ofstream out(file_name);

        if(!out.is_open())
        {
            std::cerr << "Failed to open file!" << std::endl;
            return;
        }
        
        for(int i = 0; i < this->size; i++)
        {
            out << employees[i].get_name() << " " << employees[i].get_years() << " " << employees[i].get_salary() << std::endl; 
        }

        out.close();
    }
};

int main()
{
    Employee e1;
    e1.set_name("Ivan");
    e1.set_years(25);
    e1.set_salary(2500);

    Employee e2;
    e2.set_name("Andrei");
    e2.set_years(36);
    e2.set_salary(3500);

    Employee e3;
    e3.set_name("Evtim");
    e3.set_years(45);
    e3.set_salary(5100);

    Company OOP;

    OOP.add_employee(e1);
    OOP.add_employee(e2);
    OOP.add_employee(e3);
    
    std::cout << OOP.get_most_paid().get_name() << " " << OOP.get_most_paid().get_years() << " " << OOP.get_most_paid().get_salary();

    OOP.save_to_file("resources.txt");
}