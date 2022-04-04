#include "Student.h"

const std::string& Student::getFN() const {
    return fn;
}

void Student::setFN(std::string newFN) {
    fn = newFN;
}

void Student::setFN(const std::string& newFN) {
    fn = newFN;
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