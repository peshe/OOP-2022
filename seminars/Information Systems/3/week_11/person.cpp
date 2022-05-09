#include <iostream>

using namespace std;

class Person {
    char name[64];
    int age;
public:
    Person() { cout << " Person() default " << endl; }
    Person(int age) {  cout << " Person(int age) with params" << endl; this->age = age; }
};

class Student : virtual public Person {
public:
    Student(int age) : Person(age) {
        cout << " Student(int age) with params" << endl;
    }
};

class Teacher : virtual public Person {
public:
    Teacher(int age) : Person(age) {
        cout << " Teacher(int age) with params" << endl;
    }
};

class TA : public Student, public Teacher {
public:
    TA(int age) : Student(age), Teacher(age), Person(age) { 
        cout<<" TA::TA(int age) with params"<< endl;
    }
};

int main() {
    TA nasko(21);
}