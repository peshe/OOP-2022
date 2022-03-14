#include <iostream>
#include <string>

void read (int* array, const int size) {
 
    for(int fnIndex = 0; fnIndex<size; ++fnIndex) {
        std::cin >> array[fnIndex];
    }

}

void read2 (int* array, const int size) {
 
    for(int fnIndex = 0; fnIndex<size; ++fnIndex) {
        std::cin >> array[fnIndex];
        std::cout<< array[fnIndex]<< " ";
    }
    std::cout<< std::endl;

}

int main() 
{
    const int gradesCount = 5;

    char readMode;
    void (*r)(int*, const int) = read2;
    std::cin>> readMode;
    switch(readMode) {
    case '1':
        r = read;
        break;
    case '2':
        r = read2;
        break;
    }

    int elementsSize = 0;
    std::cin >> elementsSize;
    int *fn = new int[elementsSize];
    std::string *firstNames = new std::string[elementsSize];
    std::string *lastNames = new std::string[elementsSize];
    double **grades = new double*[elementsSize];
    for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        grades[gradeIndex] = new double[gradeIndex];
    }

    r(fn, elementsSize);

    delete[] fn;
    delete[] firstNames;
    delete[] lastNames;
    for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
        delete[] grades[gradeIndex];
    }
    delete[] grades;
    
    return 0;
}