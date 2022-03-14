#include <iostream>
#include <fstream> // header file for input/output
#include <cstring>

int main() {
    // output -> вашата програма OUTPUT-ва (ЗАПИСВА) във файла
    // input -> вашата програма ЧЕТЕ от файла

    // output
    // std::ofstream out; // деклариране на поток
    // out.open("test.txt");

    // out << "I love files\n";

    // out.close();

    // // input
    // std::ifstream in;
    // in.open("test.txt");

    // char c;
    // while (in.get(c)) {
    //     std::cout << c;
    // }

    // in.close();

    // input/output
    std::fstream file;
    file.open("test2.txt", std::ios::out);

    file << "Fstream is the best append\n";

    file.close();

    file.open("test2.txt", std::ios::in);

    char c;
    file.seekp(8);
    while (file.get(c)) {
        std::cout << c;
    }

    file.close();

    // get/put pointers
    file.open("test2.txt", std::ios::out);
    file << "Fstream fstream\n";

    std::cout << file.tellg() << std::endl;
}