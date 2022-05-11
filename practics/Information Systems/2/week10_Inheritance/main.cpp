#include <iostream>

#include "Employee.h"
#include "Company.h"
#include "Developer.h"
#include "Manager.h"


bool comparator(const Employee* fstEmp,const Employee* sndEmp) {
    return strcmp(fstEmp->getName(), sndEmp->getName()) > 0;
}

int main()
{
    Company cmp(4);

    Employee* emp = new Developer("Mark", 6, true, false);
    Employee* emp1 = new Developer("John", 4, false, true);
    Employee* emp2 = new Developer("Mitko", 2, true, true);
    Employee* mng = new Manager("Peter", 5, 3);

    cmp.addEmployee(emp);
    cmp.addEmployee(emp1);
    cmp.addEmployee(emp2);
    cmp.addEmployee(mng);

    cmp.removeEmployee(emp);

    cmp.sort(&comparator);

    for (int i = 0; i < cmp.getCount(); i++) {
       std::cout << cmp.getEmployes()[i]->getName() << " " << cmp.getEmployes()[i]->getMonths() << std::endl;
    }

    return 0;
}