#include <iostream>
#include <fstream>

#include "Student.h"
#include "StudentReaderWriter.h"

void StudentReaderWriter::read(Student& student) {
    std::string fn;
    std::cin >> fn;

    std::cin >> student.fn;
    std::cin >> student.firstName;
    std::cin >> student.lastName;
    for (int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        std::cin >> student.grades[gradeIndex];
    }

    std::string formOfEducationString = "";
    bool correctFormOfEducationInput = false;
    while (!correctFormOfEducationInput) {
        std::cout << "Please, enter redovno or zadochno form of education" << std::endl;
        std::cin >> formOfEducationString;
        if (formOfEducationString == "redovno") {
            student.fe = redovno;
            correctFormOfEducationInput = true;
        }
        else if (formOfEducationString == "zadochno") {
            student.fe = zadochno;
            correctFormOfEducationInput = true;
        }
    }
}

void StudentReaderWriter::readFromFile(Student& student, std::ifstream& file) {
    file >> student.fn;
    file >> student.firstName;
    file >> student.lastName;
    for (int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        file >> student.grades[gradeIndex];
    }

    std::string formOfEducationString = "";
    file >> formOfEducationString;
    if (formOfEducationString == "redovno") {
        student.fe = redovno;
    }
    else if (formOfEducationString == "zadochno") {
        student.fe = zadochno;
    }
}

void StudentReaderWriter::writeToFile(Student& student, std::ostream& file) {
    file << student.fn << " ";
    file << student.firstName << " ";
    file << student.lastName << " ";
    for (int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        file << student.grades[gradeIndex] << " ";
    }

    switch (student.fe) {
    case redovno:
        file << "redovno";
        break;
    case zadochno:
        file << "zadocno";
        break;
    }

    file << std::endl;
}

void StudentReaderWriter::writeToBinaryFile(Student& student, std::ostream& file) {
    file.write((char*)&student, sizeof(Student));
}

void StudentReaderWriter::readFromBinaryFile(Student& student, std::istream& file) {
    file.read((char*)&student, sizeof(Student));
}