#include <iostream>
#include <cstring>

class A {};

class Person {
private:
    char name[64];
    int age;
    int birthYear;
    double weight, height;

    // copy(), delete()
public:
    /* 1. default constructor
       2. constructor with parameters
       3. copy constructor
       4. destructor  
    */

    Person() {
        this->birthYear = 1970;
    }

    Person(const char name[], int age, int birthYear, double weight, double height) {
        strcpy(this->name, name);
        this->age = age;
        this->birthYear = birthYear;
        this->weight = weight;
        this->height = height;
    }

    Person(const Person& other) {
        strcpy(this->name, other.getName());
        this->age = other.getAge();
        this->birthYear = other.getBirthYear();
        this->weight = other.getWeight();
        this->height = other.getHeight();
    }

    void greet() const {
        std::cout << "Hello, my name is " << name 
                  << " and I am " << age << " years old." 
                  << " I am born in " << birthYear << std::endl;
    }

    void printPhysicalAtributes() {
        std::cout << "I weigh " << this->weight << "kg and I am " << this->height << "cm tall." << std::endl;
    }

    const char* getName() const {
        return this->name;
    }

    void setName(const char name[]) {
        // strcpy(name, _name);
        strcpy(this->name, name);
    }

    const int getAge() const {
        return this->age;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getBirthYear() const {
        return this->birthYear;
    }

    int getWeight() const {
        return this->weight;
    }

    int getHeight() const {
        return this->height;
    }

    // constant reference
    // const A& getA(const A& data) const { 
        
    // }
};

// const T& getT() const { 
//    return data; 
// };

int main() {
    Person* p1 = new Person();
    p1->setAge(21);
    int age = p1->getAge();
    std::cout << age << std::endl;
    std::cout << p1->getBirthYear() << std::endl;

    Person p2;
    p2.setAge(43);
    std::cout << p2.getAge() << std::endl;
    p2.setName("nasko");
    std::cout << p2.getName() << std::endl;

    Person personParam("Alex", 20, 2002, 56, 170);
    personParam.greet();
    personParam.printPhysicalAtributes();

    Person copyPerson(personParam);
    personParam.greet();
    personParam.printPhysicalAtributes();
}