#include<iostream>

struct Student
{
    char name[30];
    signed fn;
    struct date
    {
        signed day;
        signed month;
        signed year;
        
    }dateOfBirth;
    

};

void printStudent(Student& student)
{
    std::cout<<student.name<<" "<<student.fn<<" "<<student.dateOfBirth.day<<":"<<student.dateOfBirth.month<<":"<<student.dateOfBirth.year<<std::endl;
}

void swap(Student& st1 , Student& st2)
{
    Student help = st1;
    st1 = st2;
    st2 = help;
}

void sortStudents(Student students[] , int size )
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (students[j].fn > students[j+1].fn)
            {
               swap(students[j] , students[j+1]);
            }
        }
    }
}

void printStudents(Student students[] , int size)
{
    for(int i = 0 ; i < size ; ++i)
    {
        printStudent(students[i]);
    }

}

int main()
{
    Student students[3]={
                            {"Georgi" , 72031 , {1 , 1 , 2001}} ,
                            {"Ivana Cvetkova" , 72013 , {1 , 1 , 2001}},
                            {"Petur" , 72033 , {1 , 1 , 2001}} 
                        };
    sortStudents(students , 3);
    printStudents(students , 3);

    return 0;
}