#include<iostream>

struct Planet
{
    char name[20];
    long double distance;
    double mass;
};

void enterPlanet(Planet& planet)
{
    std::cin.ignore();
    std::cout<<"enter planet name: ";
    std::cin.getline(planet.name , 19);
    std::cout<<'\n';
    std::cout<<"enter distance from the sun: ";
    std::cin>>planet.distance;
    std::cout<<'\n';
    std::cout<<"enter mass: ";
    std::cin>>planet.mass;
    std::cout<<'\n';
}

void printPlanet(Planet& planet)
{
    std::cout<<planet.name<<" "<<planet.distance<<" "<<planet.mass<<std::endl;
}

double calculateSeconds(Planet& planet )
{
    return (planet.distance / (double)299792);
}

int main()
{
    Planet* planets =nullptr;
    int numberOfPlanets;
    std::cout<<"neter number of planets: ";
    std::cin>>numberOfPlanets;

    planets = new Planet[numberOfPlanets];
    for(int i = 0 ; i < numberOfPlanets ; ++i)
    {
        enterPlanet(planets[i]);
    }

    for(int i = 0 ; i < numberOfPlanets ; ++i)
    {
        printPlanet(planets[i]);
    }

    

    return 0;
}