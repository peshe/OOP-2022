#include <iostream>
#include <string>

enum FormOfEducation { redovno, zaodochno };

const int gradesCount = 5;

void read (int* fns, std::string* firstNames, std::string* lastNames, double** grades, FormOfEducation* fe, const int size) {
 
    for(int fnIndex = 0; fnIndex<size; ++fnIndex) {
        std::cin >> fns[fnIndex];
        std::cin >> firstNames[fnIndex];
        std::cin >> lastNames[fnIndex];
        for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
            std::cin >> grades[fnIndex][gradeIndex];
        }
    }

}

int main() 
{
    int elementsSize = 0;
    std::cin >> elementsSize;
    int *fn = new int[elementsSize];
    std::string *firstNames = new std::string[elementsSize];
    std::string *lastNames = new std::string[elementsSize];
    double **grades = new double*[elementsSize];
    for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        grades[gradeIndex] = new double[gradeIndex];
    }
    FormOfEducation *fe = new FormOfEducation[elementsSize];

    read(fn, firstNames, lastNames, grades, fe, elementsSize);

    delete[] fn;
    delete[] firstNames;
    delete[] lastNames;
    for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        delete[] grades[gradeIndex];
    }
    delete[] grades;
    delete[] fe;
    
    return 0;
}