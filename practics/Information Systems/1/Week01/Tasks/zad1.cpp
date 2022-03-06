#include<iostream>


enum Gender
{
    Male,
    Female,
    Other
};

struct Person
{
    char name[30];
    signed age;
    Gender gender;

};

void printPerson(Person& person)
{
    std::cout<<person.name<<" "<<person.age<<" ";
    switch (person.gender)
    {
        case Male:
            std::cout<<"Male"<<std::endl;
            break;
        case Female:
            std::cout<<"Female"<<std::endl;
            break;
        case Other:
            std::cout<<"Other"<<std::endl;
            break;
        default:
        std::cout<<"unknown"<<std::endl;
            break;
    }
}

void outputByGender(Person persons[] , int size , Gender gender)
{
    for(int i = 0 ; i < size ; ++i)
    {
        if(persons[i].gender == gender)
        {
            printPerson(persons[i]);
        }
    }

}

int main()
{
    Person p[3] {   
                    {"Georgi" , 20 , Male} ,
                    {"Ivana Cvetkova" , 21 , Female},
                    {"Petur" , 20 , Male}   
                };


    Gender gender = Male;

    outputByGender(p , 3 , gender);


    return 0;
}