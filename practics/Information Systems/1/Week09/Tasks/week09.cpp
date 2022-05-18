// week09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class Person {
private:
    char* name;
    int workMonths;

    void copy(const Person& rhs)
    {
        unsigned size = strlen(rhs.name);
        name = new char[size];
        for (unsigned i = 0; i < size; ++i)
        {
            name[i] = rhs.name[i];
        }
    }

    void erase()
    {
        delete[] name;
    }

public:
    Person() {
        name = new char[1];
        name[0] = '\0';
        workMonths = 0;
    }

    Person(const char* _name, const int& _workMonths) {
        unsigned size = strlen(_name);
        for (unsigned i = 0; i < size; ++i) {
            name[i] = _name[i];
        }
    }

    Person(const Person& rhs)
    {
        copy(rhs);
    }

    Person& operator=(const Person& rhs)
    {
        if (this != &rhs)
        {
            erase();
            copy(rhs);
        }

        return *this;
    }

    ~Person()
    {
        erase();
    }

    void printPersonInfo() const {
        std::cout << name << " " << workMonths << " ";
    }
};

class Programmer : public Person {
private:
    bool knowCPlusPlus;
    bool knowCSharp;

public:
    Programmer() : Person() {
        knowCPlusPlus = false;
        knowCSharp = false;
    }

    Programmer(const char* _name, const int& _workMonths, const bool& _knowCPlusPlus, const bool& _knowCSharp) : Person(_name, _workMonths) {
        knowCPlusPlus = _knowCPlusPlus;
        knowCSharp = _knowCSharp;
    }

    void printProgrammerInfo() const {
        printPersonInfo();
        std::cout << knowCPlusPlus << knowCSharp << std::endl;
    }
};

class Manager : public Person {
private:
    int numberOfPeople;

public:
    Manager() : Person() {
        numberOfPeople = 0;
    }

    Manager(const char* _name, const int& _workMonths, const int& _numberOfPeople) : Person(_name, _workMonths) {
        numberOfPeople = _numberOfPeople;
    }

    void printManagerInfo() const {
        printPersonInfo();
        std::cout << numberOfPeople << std::endl;
    }
};

class HR {
private:
    Programmer* programmers;
    int numberOfProgrammers;
    Manager* managers;
    int numberOfManagers;

    void copy(const HR& rhs)
    {
        numberOfProgrammers = rhs.numberOfProgrammers;
        numberOfManagers = rhs.numberOfManagers;

        programmers = new Programmer[numberOfProgrammers];
        managers = new Manager[numberOfManagers];

        for (unsigned i = 0; i < numberOfProgrammers; ++i)
        {
            programmers[i] = rhs.programmers[i];
        }

        for (unsigned i = 0; i < numberOfManagers; ++i)
        {
            managers[i] = rhs.managers[i];
        }
    }

    void erase()
    {
        delete[] programmers;
        delete[] managers;
    }

public:
    HR() {
        programmers = nullptr;
        numberOfProgrammers = 0;

        managers = nullptr;
        numberOfManagers = 0;
    }

    HR(const Programmer* _programmers, const unsigned& _numberOfProgrammers, const Manager* _managers, const unsigned& _numberOfManagers) {
        numberOfProgrammers = _numberOfProgrammers;
        numberOfManagers = _numberOfManagers;

        programmers = new Programmer[numberOfProgrammers];
        managers = new Manager[numberOfManagers];

        for (unsigned i = 0; i < numberOfProgrammers; ++i)
        {
            programmers[i] = _programmers[i];
        }

        for (unsigned i = 0; i < numberOfManagers; ++i)
        {
            managers[i] = _managers[i];
        }
    }

    HR(const HR& rhs)
    {
        copy(rhs);
    }

    HR& operator=(const HR& rhs)
    {
        if (this != &rhs)
        {
            erase();
            copy(rhs);
        }

        return *this;
    }

    ~HR()
    {
        erase();
    }

    void printInfo() const {
        for (unsigned i = 0; i < numberOfProgrammers; ++i)
        {
            programmers[i].printProgrammerInfo();
        }

        for (unsigned i = 0; i < numberOfManagers; ++i)
        {
            managers[i].printManagerInfo();
        }
    }

};

int main()
{

    return 0;
}