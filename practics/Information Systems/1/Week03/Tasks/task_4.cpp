#include <iostream>
#include <fstream>

struct Student
{
    unsigned fn;
    unsigned passedExams;
    unsigned unpassedExams;
    double averageScore;
};

void writeStudentsToBinaryFile(const char* fileName, const Student* students, const unsigned numberOfStudents) {
    std::ofstream binaryFile(fileName, std::ios::binary);

    if (binaryFile.is_open()) {
        for (unsigned i = 0; i < numberOfStudents; i++)
        {
            binaryFile.write((const char*)&students[i].fn, sizeof(unsigned));
            binaryFile.write((const char*)&students[i].passedExams, sizeof(unsigned));
            binaryFile.write((const char*)&students[i].unpassedExams, sizeof(unsigned));
            binaryFile.write((const char*)&students[i].averageScore, sizeof(double));
        }

        binaryFile.close();
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }
}

void readStudentsFromBinaryFile(const char* fileName, const Student* students, const unsigned numberOfStudents) {
    std::ifstream binaryFile(fileName, std::ios::binary);
    
    if (binaryFile.is_open()) {
        for (unsigned i = 0; i < numberOfStudents; i++)
        {
            binaryFile.read((char*)&students[i].fn, sizeof(unsigned));
            binaryFile.read((char*)&students[i].passedExams, sizeof(unsigned));
            binaryFile.read((char*)&students[i].unpassedExams, sizeof(unsigned));
            binaryFile.read((char*)&students[i].averageScore, sizeof(double));
        }
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }
}

unsigned* sortStudents(Student* students, const unsigned numberOfStudents) {
    unsigned sortedFN[100] = {};
    
    for (unsigned i = 0; i < numberOfStudents; i++)
    {
        sortedFN[i] = students[i].fn;
    }

    for (unsigned i = 0; i < numberOfStudents - 1; i++)
    {
        for (unsigned j = 0; j < numberOfStudents - i - 1; j++) 
        {
            std::cout << sortedFN[j] << std::endl;
            if (sortedFN[j] > sortedFN[j + 1])
            {
                unsigned temp = sortedFN[j];
                sortedFN[j] = sortedFN[j + 1];
                sortedFN[j + 1] = temp;
            }
        }
    }

    return sortedFN;
}

int main()
{
    Student students[3]{
                    {62563, 2, 5, 4.5},
                    {62564, 0, 7, 6},
                    {62565, 4, 3, 3.5}
    };

    writeStudentsToBinaryFile("students.bin", students, 3);

    Student studentsFromFile[3];
    readStudentsFromBinaryFile("students.bin", studentsFromFile, 3);

    unsigned* sortedStudents = sortStudents(studentsFromFile, 3);

    for (unsigned i = 0; i < 3; i++)
    {
        std::cout << sortedStudents[i] << std::endl;
    }

    return 0;
}