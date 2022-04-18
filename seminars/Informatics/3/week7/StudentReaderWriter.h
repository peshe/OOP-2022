#pragma once

class StudentReaderWriter {

public:
    void read(Student& student);

    void readFromFile(Student& student, std::ifstream& file);

    void writeToFile(Student& student, std::ostream& file);

    void writeToBinaryFile(Student& student, std::ostream& file);

    void readFromBinaryFile(Student& student, std::istream& file);
};