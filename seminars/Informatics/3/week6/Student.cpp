#include "Student.h"
#include "StringUtils.h"

void Student::clean() {
    delete[] fn;
    fn = nullptr;
    delete[] firstName;
    firstName = nullptr;
    delete[] lastName;
    lastName = nullptr;
}

void Student::copy(const Student& other, bool withClean) {
    if (withClean) {
        clean();
    }
    StringUtils utils;

    fn = new char[utils.strlen(other.fn) + 1];
    utils.strcpy(fn, other.fn);
    firstName = new char[utils.strlen(other.firstName) + 1];
    utils.strcpy(firstName, other.firstName);
    lastName = new char[utils.strlen(other.lastName) + 1];
    utils.strcpy(lastName, other.lastName);

    for (int i = 0; i < gradesCount; ++i) {
        grades[i] = other.grades[i];
    }
    fe = other.fe;
}

Student::Student(const char* fn,
                 const char* firstName, 
                 const char* lastName, 
                 double grades[gradesCount], 
                 FormOfEducation fe) :
                grades(),
                fe(fe)
{
    StringUtils utils;
    this->fn = new char[utils.strlen(fn) + 1];
    utils.strcpy(this->fn, fn);
    this->firstName = new char[utils.strlen(firstName) + 1];
    utils.strcpy(this->firstName, firstName);
    this->lastName = new char[utils.strlen(lastName) + 1];
    utils.strcpy(this->lastName, lastName);

    if (grades != nullptr) {
        for (int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
            this->grades[gradeIndex] = grades[gradeIndex];
        }
    }
}

Student::Student(const Student& other) {
    copy(other, false);
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        copy(other);
    }
    return *this;
}

Student::~Student() {
    clean();
}

const char* Student::getFN() const {
    return fn;
}

void Student::setFN(const char* newFN) {
    StringUtils utils;
    delete[] fn;
    fn = new char[utils.strlen(newFN) + 1];
    utils.strcpy(fn, newFN);
}

const char* Student::getFirstName() const {
    return firstName;
}

void Student::setFirstName(const char* newFirstName) {
    StringUtils utils;
    delete[] firstName;
    firstName = new char[utils.strlen(newFirstName) + 1];
    utils.strcpy(firstName, newFirstName);
}

const char* Student::getLastName() const {
    return lastName;
}

void Student::setLastName(const char* newLastName) {
    StringUtils utils;
    delete[] lastName;
    lastName = new char[utils.strlen(newLastName) + 1];
    utils.strcpy(lastName, newLastName);
}

bool Student::isInformatics() {
    return fn[0] == '8';
}

double Student::meanGrade() {
    double res = 0;

    for (int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        res += grades[gradeIndex];
    }

    return res / 5;
}

double Student::maxGrade() {
    double max = grades[0];

    for (int gradeIndex = 1; gradeIndex < gradesCount; ++gradeIndex) {
        if (grades[gradeIndex] > max) {
            max = grades[gradeIndex];
        }
    }
    return max;
}