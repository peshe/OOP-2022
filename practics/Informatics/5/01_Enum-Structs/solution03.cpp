#include<iostream>
#include<cstring> 

const size_t MAX_LEN = 16;
const size_t SIZE    = 8;

using std::cin;
using std::cout;
using std::endl;

enum COLOR {

	BROWN,  // 0
	GREEN,  // 1
	YELLOW, // 2
	BLUE    // 3
};

COLOR readEnum(char text[]) {

	/*
	* Тук слагаме начална стойност на променливата input, защото
	* ако потребителя НЕ въведе коректно низа в конзолата,
	* програмата ще изведе грешка, че се опитваме да врънем нещо което не е
	* инициализирано. Изпускаме проверката за GREEN, тъй като 
	* сме казали, че то ще бъде равно на GREEN и така изпускаме  
	* повторно присвояване на променливата input със стойност GREEN.
	*/
	COLOR input = COLOR::GREEN;

	cin.getline(text, SIZE, ' ');

	if (strcmp(text, "brown") == 0 || strcmp(text, "BROWN") == 0) {

		input = COLOR::BROWN;

	} else if (strcmp(text, "yellow") == 0 || strcmp(text, "YELLOW") == 0) {

		input = COLOR::YELLOW;

	} else if (strcmp(text, "blue") == 0 || strcmp(text, "BLUE") == 0) {

		input = COLOR::BLUE;
	}

	return input;
}

// Втори начин за четене на enum от конзолата
COLOR readEnumWithNumber(size_t numberOfColor) {

	COLOR input = COLOR::BLUE; // 3

	cin >> numberOfColor;

	if (numberOfColor == 0) {

		input = COLOR::BROWN;

	} else if (numberOfColor == 1) {

		input = COLOR::GREEN;

	} else if (numberOfColor == 2) {

		input = COLOR::YELLOW;
	}

	return input;
}

void printEnum(const COLOR& c) {

	if (c == COLOR::GREEN) {

		cout << "green\n";

	} else if (c == COLOR::BROWN) {

		cout << "brown\n";

	} else if (c == COLOR::YELLOW) {

		cout << "yellow\n";

	} else if (c == COLOR::BLUE) {

		cout << "blue\n";
	}
}

struct Person { 

	COLOR  eyes;
	COLOR  hair;
	size_t year;
	char   name[MAX_LEN]{"none\n"};
};

void readPerson(Person& person) {

	cout << "Enter color of eyes:";
	char inputEyes[SIZE];
	person.eyes = readEnum(inputEyes);


	cout << "Enter color of hair:";
	char inputHair[SIZE];
	person.eyes = readEnum(inputHair);


	size_t year;
	do {
		cout << "Enter how old is the person:";
		cin >> year;
	} while (year <= 0 || year > 150); // Проверка за въведените години

	person.year = year;


	cout << "Enter name of the person:";
	char inputName[MAX_LEN];
	cin.getline(inputName, MAX_LEN, ' ');
	strcpy_s(person.name, MAX_LEN, inputName);
}

void printPerson(const Person& person) {

	cout << "The name of person is: "   << person.name << endl
		 << "Years of the person are: " << person.year << endl;

	cout << "Color of eyes are: ";
	printEnum(person.eyes);

	cout << "Color of hair is: ";
	printEnum(person.hair);
}

struct Address {
	
	size_t streetNumber;
	char   country[MAX_LEN];
	char   city[MAX_LEN];
	char   street[MAX_LEN];
};

void readAddress(Address& input) {

	cout << "Enter country:";
	cin.getline(input.country, MAX_LEN, ' ');

	cout << "Enter city:";
	cin.getline(input.city, MAX_LEN, ' ');

	cout << "Enter street:";
	cin.getline(input.street, MAX_LEN, ' ');

	cout << "Enter streen number:";
	cin >> input.streetNumber;
}

void printAddress(const Address& input) {

	cout << "Country: "  << input.country << "\nCity: " << input.city
		 << "\nStreet: " << input.street  << "\nStreet number: " << input.streetNumber << endl;
}

struct Apartment {

	bool    isFree;
	double  rent;
	Person  owner;
	Person  tenant;
	Address addressApartment;
};

void readApartment(Apartment& input) {

	cout << "Enter information about owner:\n";
	readPerson(input.owner);

	cout << "Enter information about tenant:\n";
	readPerson(input.tenant);

	if (strcmp(input.tenant.name, "none") == 0) {
		input.isFree = false;
	} else {
		input.isFree = true;
	}

	cout << "Enter information about address:\n";
	readAddress(input.addressApartment);

	do {
		cout << "Enter apartment rent: ";
		cin >> input.rent;
	} while (input.rent <= 0);
}

void printApartment(const Apartment& input) {

	cout << "Owner information:\n";
	printPerson(input.owner);

	cout << "Address information:\n";
	printAddress(input.addressApartment);

	cout << "Rent: " << input.rent << endl;

	cout << "Is it for rent: "; 
	if (input.isFree) {

		cout << "YES\n"; 
		cout << "Tenant:\n";
		printPerson(input.tenant);

	} else {
		cout << "NO\n";
	}
}

bool isApartmentRented(const Apartment& apartment) {

	return apartment.isFree;
}

bool gavesToRent(Apartment& apartment) {

	if (!apartment.isFree) {
		return false;
	}

	apartment.isFree = true;

	do {
		cout << "Enter rent:";
		cin >> apartment.rent;
	} while (apartment.rent <= 0);

	cout << "Enter information about tenant:\n";
	readPerson(apartment.tenant);

	return true;
}

void saleApartment(Apartment& apartment, const Person& newOwner) {

	apartment.owner.eyes = newOwner.eyes;
	apartment.owner.hair = newOwner.hair;
	apartment.owner.year = newOwner.year;
	strcpy_s(apartment.owner.name, MAX_LEN, newOwner.name);
}

void searchApartment(Apartment arrApartment[], const double& rent, const size_t& numOfApartment) {

	for (size_t i = 0; i < numOfApartment; ++i) {

		if (arrApartment[i].rent == rent || (arrApartment[i].rent <= rent + 150 || arrApartment[i].rent >= rent - 150)) {
			printAddress(arrApartment[i].addressApartment);
		}
	}
}

int main() {

	return 0;
}
