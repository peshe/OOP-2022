#include <iostream>
#include <fstream>
#include <string>

#include "Student.h"
#include "StudentCollection.h"
#include "StudentReaderWriter.h"

int main() 
{
    std::string command;
    Student *students_arr = new Student[0];
    int elementsSize = 0;
    StudentCollection students;

    //meanGrade(students_arr[2]);
    //students_arr[2].meanGrade();

    StudentReaderWriter srw;

    while(true) {
        std::cin>> command;
        if(command == "quit") {
            break;
        } else if(command == "fi") {
            std::string pathToFile;
            std::cin>> pathToFile;
            std::ifstream file(pathToFile);
            file>> elementsSize;

            delete [] students_arr;
            students_arr = new Student[elementsSize];

            for(int studentIndex = 0; studentIndex < elementsSize; ++studentIndex) {
                srw.readFromFile(students_arr[studentIndex], file);
            }

            file.close();
        } else if(command == "o") {
            std::cout<< elementsSize<< std::endl;
            for(int studentIndex = 0; studentIndex < elementsSize; ++studentIndex) {
                srw.writeToFile(students_arr[studentIndex], std::cout);
            }
        } else if(command == "fo") {
            std::string pathToFile;
            std::cin>> pathToFile;
            std::ofstream file(pathToFile, std::ios::out);

            file<< elementsSize;
            for(int studentIndex = 0; studentIndex < elementsSize; ++studentIndex) {
                srw.writeToFile(students_arr[studentIndex], file);
            }

            file.close();
        }
    }
    delete [] students_arr;
    
    return 0;
}