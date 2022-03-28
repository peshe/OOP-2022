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
            binaryFile.write((const char*)&students[i], sizeof(Student));
        }

        binaryFile.close();
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }
}

void studentsFromBinaryFile(const char* fileName, const char* fileNameForPointer, const Student* students, const unsigned numberOfStudents) {
    std::ifstream binaryFile(fileName, std::ios::binary);
    std::ofstream binaryFileWithPointer(fileNameForPointer, std::ios::binary);

    unsigned position;

    if (binaryFile.is_open() && binaryFileWithPointer.is_open()) {
        for (unsigned i = 0; i < numberOfStudents; i++)
        {
            binaryFile.read((char*)&students[i], sizeof(Student));
            if (students[i].averageScore >= 4) {
                position = binaryFileWithPointer.tellp();
                binaryFileWithPointer.write((const char*)&position, sizeof(unsigned));
            }
        }
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }
}

void readPositionsFromBinaryFile(const char* fileName) {
    std::ifstream binaryFile(fileName, std::ios::binary);

    unsigned position[256];
    unsigned index = 0;

    if (binaryFile.is_open()) {
        while (!binaryFile.eof()) {
            binaryFile.read((char*)&position[index++], sizeof(unsigned));
        }
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }

    //the last position is set two times in position array - print all element without the last
    for (unsigned i = 0; i < index - 1; ++i) {
        std::cout << position[i] << std::endl;
    }
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
    studentsFromBinaryFile("students.bin", "positions.bin", studentsFromFile, 3);

    readPositionsFromBinaryFile("positions.bin");

    return 0;
}