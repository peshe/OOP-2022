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
    double salary;

};

struct Car
{
    double price;
    char color[20];
    char brand[20];
    char model[30];
};

void canBuy(Person buyers[] , int numberOfBuyers , Car cars[] , int numberOfCars)
{
    bool cantBuyAny = true;
    for(int  i =0 ; i < numberOfBuyers ; ++i)
    {
        std::cout<<buyers[i].name<<": "<<std::endl;
        for(int j = 0 ; j < numberOfCars ; ++j)
        {
            if(buyers[i].salary > (cars[j].price * 0.30))
            {
                std::cout<<" "<< cars[j].brand<< " "<<cars[j].model<<std::endl;
                cantBuyAny = false;
            }
        }
        if(cantBuyAny)
        {
            std::cout<<"can't buy any of the cars"<<std::endl;
        }
        cantBuyAny = true;

    }
}

int main()
{
    Person p[3] {   
                    {"Georgi" , 20 , Male , 1200} ,
                    {"Ivana Cvetkova" , 21 , Female , 3500},
                    {"Petur" , 20 , Male , 2000}   
                };
    Car cars[3] {   
                    {1000 , "red" , "Mercedes" , "c180"} ,
                    {800 , "black" , "Mercedes" , "w180"},
                    {8100 , "silver" , "Mercedes" , "300 SL"}   
                }; 
    canBuy(p , 3 , cars , 3);

    return 0;
}