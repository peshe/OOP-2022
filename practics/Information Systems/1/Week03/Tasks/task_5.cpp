#include <iostream>
#include <fstream>
#include <string>

void addPositionToFile(const char* fileName, const unsigned position) {
    std::ofstream fileOut("positions_of_numbers.bin", std::ios::binary | std::ios::app);

    if (fileOut.is_open()) {
        fileOut.write((const char*)&position, sizeof(unsigned));
        fileOut.close();
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }
}

void positionsOfNumbers(const char* fileName, const unsigned sizeOfString) {
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "Unable to open" << std::endl;
        return;
    }

    file.seekg(4, std::ios::beg);

    for (unsigned i = 0; i < sizeOfString; i++)
    {
        char symbol;
        file.read((char*)&symbol, sizeof(char));
        if (symbol > '0' && symbol < '9') {
            addPositionToFile("positions_of_numbers.bin", file.tellg());
        }
    }

    file.close();
}

void lastNumber(const char* fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (file.is_open())
    {
        file.seekg(-4, std::ios::end);

        unsigned position;
        file.read((char*)&position, sizeof(unsigned));

        std::cout << position << std::endl;

        file.close();
    }
}

int main()
{
    positionsOfNumbers("test.bin", 4);
    lastNumber("positions_of_numbers.bin");

    return 0;
}