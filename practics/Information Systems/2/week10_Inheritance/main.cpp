#include <iostream>

#include "Employee.h"
#include "Company.h"
#include "Developer.h"
#include "Manager.h"


bool moreExperience(const Employee* fstEmp,const Employee* sndEmp) {
    
    return fstEmp->getMonths() > sndEmp->getMonths();
}

int main()
{
    Company cmp(5);

    Developer emp("Mark", 6, true, false);
    Developer emp1("John", 4, false, true);
    Developer emp2("Mitko", 2, true, true);
    Manager mng("Peter", 5, 3);

    cmp.addEmployee(emp);
    cmp.addEmployee(emp1);
    cmp.addEmployee(emp2);
    cmp.addEmployee(mng);

    cmp.removeEmployee(emp1);

    cmp.sort(&moreExperience);

    for (int i = 0; i < cmp.getCount(); i++) {
       std::cout << cmp.getEmployes()[i]->getName() << " " << cmp.getEmployes()[i]->getMonths() << std::endl;
    }


    return 0;
}