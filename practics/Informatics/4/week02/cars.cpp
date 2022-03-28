#include <iostream>
#include <fstream>
 
struct Car 
{
    char make[32];
    double price;
    size_t horsePower;
    double engineVolume;
    bool isANewCar;
};
 
void readCarFromFile(Car& car, std::ifstream& input) 
{
    input.getline(car.make, 32, '\0');
    input >> car.price >> car.horsePower >> car.engineVolume >> car.isANewCar;
}
  
void writeCarToFile(const Car& car, std::ofstream& output) 
{
    output << car.make << '\n' << car.price << '\n' << car.horsePower << '\n' << car.engineVolume << '\n' << car.isANewCar << '\n';
}

int main() 
{
    const int CARS_SIZE = 5;
    Car cars[CARS_SIZE];

    std::ifstream input("backup.txt");
    if (!input.is_open()) 
    {
        std::cout << "Failed to open file!" << std::endl;
        return -1;
    }
 
    std::ofstream oldCars("old_cars.txt");
    if (!oldCars.is_open()) 
    {
        std::cout << "Failed to open file!" << std::endl;
        return -1;
    }
 
    std::ofstream newCars("new_cars.txt");
    if (!newCars.is_open()) 
    {
        std::cout << "Failed to open file!" << std::endl;
        return -1;
    }
 
    for (size_t i = 0; i < CARS_SIZE; i++) 
    {
        input >> cars[i].make >> cars[i].price >> cars[i].horsePower >> cars[i].engineVolume >> cars[i].isANewCar;
    }

    for (size_t i = 0; i < CARS_SIZE; i++) 
    {
        if (cars[i].isANewCar) 
        {
            writeCarToFile(cars[i], newCars);
        } else 
        {
            writeCarToFile(cars[i], oldCars);
        }
    }
 
    input.close();
    newCars.close();
    oldCars.close();
 
    return 0;
}
