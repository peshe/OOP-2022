#include <iostream>
#include <fstream>
#include <string>

void addStringToBinaryFile(const char* fileName, const std::string& myString) {
    std::ofstream binaryFile(fileName, std::ios::binary);
    if (binaryFile.is_open()) {
        unsigned size = myString.size();
        binaryFile.write((const char*)&size, sizeof(unsigned));
        binaryFile.write(myString.c_str(), size);
        binaryFile.close();
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }
}

std::string changeSmallLettersToCapital(std::string inputString) {
    unsigned sizeOfString = inputString.size();
    for (unsigned i = 0; i < sizeOfString; ++i) {
        if (islower(inputString[i])) {
            inputString[i] = toupper(inputString[i]);
        }
    }

    return inputString;
}

int main()
{
    std::string changedString = changeSmallLettersToCapital("abFgTyu");
    addStringToBinaryFile("test.bin", changedString);

    return 0;
}