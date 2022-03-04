#include <iostream>
#include <string>

//const int this_is_var; // snake case
//const int thisIsVar; // camel case
//const int THIS_IS_CONSTANT; // screaming snake case

enum FormOfEducation { redovno, zadochno };

const int gradesCount = 5;

struct Student {
    int fn;
    std::string firstName;
    std::string lastName;
    double grades[5];
    FormOfEducation fe;
};

void read (Student& student) {
 
    std::cin >> student.fn;
    std::cin >> student.firstName;
    std::cin >> student.lastName;
    for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        std::cin >> student.grades[gradeIndex];
    }
    
    std::string formOfEducationString = "";
    bool correctFormOfEducationInput = false;
    while(!correctFormOfEducationInput) {
        std::cout<< "Please, enter redovno or zadochno form of education"<< std::endl;
        std::cin>> formOfEducationString;
        if(formOfEducationString == "redovno") {
            student.fe = redovno;
            correctFormOfEducationInput = true;
        } else if (formOfEducationString == "zadochno") {
            student.fe = zadochno;
            correctFormOfEducationInput = true;
        }
    }
}


void print (const Student& student) {
 
    std::cout << student.fn << " ";
    std::cout << student.firstName << " ";
    std::cout << student.lastName << " ";
    for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        std::cout << student.grades[gradeIndex] << " ";
    }
    
    switch(student.fe) {
    case redovno:
        std::cout << "redovno" << " ";
        break;
    case zadochno:
        std::cout << "zadocno" << " ";
        break;
    }

    std::cout<< std::endl;
}

int main() 
{

    int elementsSize = 0;
    std::cin >> elementsSize;
    Student *students_arr = new Student[elementsSize];

    for(int studentIndex = 0; studentIndex < elementsSize; ++studentIndex) {
        read(students_arr[studentIndex]);
    }

    for(int studentIndex = 0; studentIndex < elementsSize; ++studentIndex) {
        print(students_arr[studentIndex]);
    }

    delete[] students_arr;
    
    return 0;
}