#include <iostream>
#include <fstream>
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

void readFromFile (Student& student, std::ifstream& file) {
    file >> student.fn;
    file >> student.firstName;
    file >> student.lastName;
    for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        file >> student.grades[gradeIndex];
    }
    
    std::string formOfEducationString = "";
    file>> formOfEducationString;
    if(formOfEducationString == "redovno") {
        student.fe = redovno;
    } else if (formOfEducationString == "zadochno") {
        student.fe = zadochno;
    }
}

void writeToFile (Student& student, std::ostream& file) {
    file << student.fn << " ";
    file << student.firstName << " ";
    file << student.lastName << " ";
    for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        file << student.grades[gradeIndex] << " ";
    }
    
    switch(student.fe) {
    case redovno:
        file << "redovno";
        break;
    case zadochno:
        file << "zadocno";
        break;
    }

    file<< std::endl;
}

void writeToBinaryFile (Student& student, std::ostream& file) {
    file.write((char*) &student, sizeof(Student));
}

void readFromBinaryFile (Student& student, std::istream& file) {
    file.read((char*) &student, sizeof(Student));
}

int main() 
{

    int elementsSize = 0;
    std::ifstream file("studentsI.txt");
    file>> elementsSize;
    Student *students_arr = new Student[elementsSize];

    for(int studentIndex = 0; studentIndex < elementsSize; ++studentIndex) {
        readFromFile(students_arr[studentIndex], file);
    }


    std::ofstream file2("studentsO.txt", std::ios::out);
    std::ofstream fileB("studentsB", std::ios::out | std::ios::binary);
    fileB.write((char*) &elementsSize, sizeof(int));
    std::cout<< elementsSize<< std::endl;
    for(int studentIndex = 0; studentIndex < elementsSize; ++studentIndex) {
        writeToBinaryFile(students_arr[studentIndex], fileB);
    }

    fileB.close();

    std::ifstream file2B("studentsB", std::ios::binary);
    file.read((char*) &elementsSize, sizeof(int)); 
    std::cout<< elementsSize<< "\n";

    for(int studentIndex = 0; studentIndex < elementsSize; ++studentIndex) {
        readFromBinaryFile(students_arr[studentIndex], file);
        writeToFile(students_arr[studentIndex], std::cout);
    }

    file2B.close();

    delete[] students_arr;

    file.close();
    file2.close();
    
    return 0;
}