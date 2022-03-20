#include <iostream>
#include <fstream>
#include <string>

void createBinaryFileWithNumber(const char* fileName, const unsigned number) {
    std::ofstream binaryFile(fileName, std::ios::binary);

    if (binaryFile.is_open()) {
        binaryFile.write((const char*)&number, sizeof(unsigned));
        binaryFile.close();
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }
}

unsigned getNumberFromBinaryFile(const char* fileName) {
    std::ifstream binaryFile(fileName, std::ios::binary);
    unsigned number = 0;
    if (binaryFile.is_open()) {
        binaryFile.read((char*)&number, sizeof(unsigned));
        binaryFile.close();
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }

    return number;
}

void createBinaryFileWithChar(const char* fileName, const char symbol) {
    std::ofstream binaryFile(fileName, std::ios::binary);

    if (binaryFile.is_open()) {
        binaryFile.write(&symbol, sizeof(char));
        binaryFile.close();
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }
}

char getCharFromBinaryFile(const char* fileName) {
    std::ifstream binaryFile(fileName, std::ios::binary);
    char symbol = ' ';
    if (binaryFile.is_open()) {
        binaryFile.read(&symbol, sizeof(char));
        binaryFile.close();
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }

    return symbol;
}

int main()
{
    createBinaryFileWithNumber("test.bin", 12);
    unsigned number = getNumberFromBinaryFile("test.bin");
    std::cout << number << std::endl;

    createBinaryFileWithChar("test.bin", 'a');
    char symbol = getCharFromBinaryFile("test.bin");
    std::cout << symbol << std::endl;

    return 0;
}