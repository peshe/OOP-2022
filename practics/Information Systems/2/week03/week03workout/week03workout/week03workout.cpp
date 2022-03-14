#include <iostream>
#include <fstream>
#include <string>

int length(const char text[])
{
	int i = 0;

	while (text[i] != '\0')
	{
		i++;
	}

	return i;
}

enum class TYPE_ANIMAL
{
	UNKNOWN = -1,
	DOG,
	CAT,
	RABBIT,
	END
};

struct Animal
{
	TYPE_ANIMAL animal_type;
	char name[20];
	int age;
	char gender;
};

struct ZooMag
{
	char storeName[20];
	const int capacity = 50;
	Animal listOfAnimals[50];
	int numberOfAnimals;
};

void printInfo(const TYPE_ANIMAL type, const char nameAnimal[20], const ZooMag& storeName)
{
	for (int i = 0; i < storeName.numberOfAnimals; i++)
	{
		if (strcmp(storeName.listOfAnimals[i].name, nameAnimal) == 0 && storeName.listOfAnimals[i].animal_type == type) {
			std::cout << storeName.listOfAnimals[i].name << std::endl;

			if (storeName.listOfAnimals[i].animal_type == TYPE_ANIMAL::DOG)	std::cout << "Dog" << std::endl;
			else if (storeName.listOfAnimals[i].animal_type == TYPE_ANIMAL::CAT) std::cout << "Cat" << std::endl;
			else if (storeName.listOfAnimals[i].animal_type == TYPE_ANIMAL::RABBIT)	std::cout << "Rabbit" << std::endl;
			else if (storeName.listOfAnimals[i].animal_type == TYPE_ANIMAL::UNKNOWN) std::cout << "Unknown" << std::endl;

			std::cout << storeName.listOfAnimals[i].age << std::endl << storeName.listOfAnimals[i].age << std::endl;
		}
	}
}

void addAnimalToStoreList(ZooMag& obj, const Animal& someAnimal)
{
	if (obj.numberOfAnimals < obj.capacity)
	{
		obj.listOfAnimals[obj.numberOfAnimals].animal_type = someAnimal.animal_type;
		int size = length(someAnimal.name);

		for (int i = 0; i < size; i++)
		{
			obj.listOfAnimals[obj.numberOfAnimals].name[i] = someAnimal.name[i];
		}

		obj.listOfAnimals[obj.numberOfAnimals].name[size] = '\0';
		obj.listOfAnimals[obj.numberOfAnimals].age = someAnimal.age;
		obj.listOfAnimals[obj.numberOfAnimals].gender = someAnimal.gender;
		obj.numberOfAnimals++;
	}
	else
	{
		std::cout << "The store is full.";
	}
}

void saveToFile(const char* filePath, const Animal& obj) {
	// animals.txt
	// source.cpp

	std::ofstream myFile(filePath, std::ios::out | std::ios::trunc);

	if (!myFile.is_open()) {
		std::cout << "Couldn't open file " << filePath << '\n';
		return;
	}

	// <<, >>
  //Име на животното
  //Вид на животното(куче, котка, заек)
  //Години
  //Пол

	if (obj.animal_type == TYPE_ANIMAL::DOG) myFile << "dog";
	else if (obj.animal_type == TYPE_ANIMAL::CAT) myFile << "cat";
	else if (obj.animal_type == TYPE_ANIMAL::RABBIT) myFile << "rabbit";
	else if (obj.animal_type == TYPE_ANIMAL::UNKNOWN) myFile << "-";

	myFile << '\n';
	int size = length(obj.name);

	for (int i = 0; i < size; i++)
	{
		myFile << obj.name[i];
	}

	myFile << '\n' << obj.age << '\n' << obj.gender << '\n';

	myFile.close();
}

void readFromFile(const char* filePath, Animal& obj)
{
	//type
	//name
	//age
	//gender

	std::ifstream myFile;
	myFile.open(filePath);

	char type[20];
	myFile >> type;

	if (strcmp(type, "dog") == 0)
	{
		obj.animal_type = TYPE_ANIMAL::DOG;
	}
	else if (strcmp(type, "cat") == 0)
	{
		obj.animal_type = TYPE_ANIMAL::CAT;
	}
	else if (strcmp(type, "rabbit") == 0)
	{
		obj.animal_type = TYPE_ANIMAL::RABBIT;
	}
	else
	{
		obj.animal_type = TYPE_ANIMAL::UNKNOWN;
	}

	myFile >> obj.name;
	myFile >> obj.age;
	myFile >> obj.gender;
	myFile.close();
}

int main()
{
	return 0;
}
//CONOR