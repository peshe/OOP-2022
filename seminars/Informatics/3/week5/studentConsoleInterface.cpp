#include <iostream>
#include <fstream>
#include <string>

//const int this_is_var; // snake case
//const int thisIsVar; // camel case
//const int THIS_IS_CONSTANT; // screaming snake case

enum FormOfEducation { redovno, zadochno };

const int gradesCount = 5;

class Student {
    std::string fn;
    std::string firstName;
    std::string lastName;
    double grades[gradesCount];
    FormOfEducation fe;

    char* middleName;

public:

    const std::string& getFN() const {
        return fn;
    }

    void setFN(std::string newFN) {
        fn = newFN;
    }

    void setFN(const std::string& newFN) {
        fn = newFN;
    }

    bool isInformatics() {
        return fn[0] == '8';
    }

    double meanGrade() {
        double res = 0;
        
        for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
            res += grades[gradeIndex];
        }

        return res / 5;
    }

    double maxGrade() {
        double max = grades[0];
        
        for(int gradeIndex = 1; gradeIndex < gradesCount; ++gradeIndex) {
            if(grades[gradeIndex] > max) {
                max = grades[gradeIndex];
            }
        }
        return max;
    }

    friend class StudentReaderWriter;
};

class StudentReaderWriter {

public:
    void read (Student& student) {
 
        std::string fn;
        std::cin >> fn;

        std::cin >> student.fn;
        std::cin >> student.firstName;
        std::cin >> student.lastName;
        for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
            std::cin >> student.grades[gradeIndex];
        }
        
        std::string formOfEducationString = "";
        bool correctFormOfEducationInput = false;
        while(!correctFormOfEducationInput) {
            std::cout<< "Please, enter redovno or zadochno form of education"<< std::endl;
            std::cin>> formOfEducationString;
            if(formOfEducationString == "redovno") {
                student.fe = redovno;
                correctFormOfEducationInput = true;
            } else if (formOfEducationString == "zadochno") {
                student.fe = zadochno;
                correctFormOfEducationInput = true;
            }
        }
    }

    void readFromFile (Student& student, std::ifstream& file) {
        file >> student.fn;
        file >> student.firstName;
        file >> student.lastName;
        for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
            file >> student.grades[gradeIndex];
        }
        
        std::string formOfEducationString = "";
        file>> formOfEducationString;
        if(formOfEducationString == "redovno") {
            student.fe = redovno;
        } else if (formOfEducationString == "zadochno") {
            student.fe = zadochno;
        }
    }

    void writeToFile (Student& student, std::ostream& file) {
        file << student.fn << " ";
        file << student.firstName << " ";
        file << student.lastName << " ";
        for(int gradeIndex = 0; gradeIndex < gradesCount; ++gradeIndex) {
            file << student.grades[gradeIndex] << " ";
        }
        
        switch(student.fe) {
        case redovno:
            file << "redovno";
            break;
        case zadochno:
            file << "zadocno";
            break;
        }

        file<< std::endl;
    }

    void writeToBinaryFile (Student& student, std::ostream& file) {
        file.write((char*) &student, sizeof(Student));
    }

    void readFromBinaryFile (Student& student, std::istream& file) {
        file.read((char*) &student, sizeof(Student));
    }
};



int main() 
{
    std::string command;
    Student *students_arr = new Student[0];
    int elementsSize = 0;

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