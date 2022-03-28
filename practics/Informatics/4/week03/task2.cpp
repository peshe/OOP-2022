#include <iostream>
#include <fstream>

struct Student 
{
    char name[32];
    int facNum;
    char email[32];
    size_t passedExams;
    size_t failedExams;
    double avgGrade;
};


void writeToFile(Student* students, std::ofstream& out)
{
    for(size_t i = 0; i < 3; i++)
    {
        out.write((char*)&students[i], sizeof(Student));
    }
}

int* facultyNumbers(Student* students, std::ifstream& in)
{
    for(size_t i = 0; i < 3; i++)
    {
        in.read((char*)&students[i], sizeof(Student));
    }

    int max;
    for(size_t i = 0; i < 2; i++)
    {
        max = i;
        for(size_t j = i + 1; j < 3; j++)
        {
            if(students[j].avgGrade < students[max].avgGrade)
            {
                max = j;
            }
            std::swap(students[max], students[j]);
        }
    }

    int *arrayOfNumbers;
    for(size_t i = 0; i < 3; i++)
    {
        arrayOfNumbers[i] = students[i].facNum;
    }

    return arrayOfNumbers;

}


int main ()
{
    Student students[3] = 
    {
        {"Ivan", 45506, "ivan@abv.bg", 4, 3, 4.50}, 
        {"Georgi", 47865, "gosho@yahoo.com", 5, 2, 4.65},
        {"Pesho", 45555, "pesho@gmail.com",  6, 1, 5.75}
    };

    std::ofstream out("students.bin", std::ios::binary);
    if(!out.is_open())
    {
        std::cout << "Error!" << std::endl;
        return -1;
    }

    writeToFile(students, out);
    out.close();

    std::ifstream in("students.bin", std::ios::binary);
    if(!in.is_open())
    {
        std::cout << "Error!" << std::endl;
        return -1;
    }

    int* arrayOfFacultyNumbers = facultyNumbers(students, in);

    for(size_t i = 0; i < 3; i++)
    {
        std::cout << arrayOfFacultyNumbers[i] << std::endl;
    }
    
    in.close();

    return 0;

}

