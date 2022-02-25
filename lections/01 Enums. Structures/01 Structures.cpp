/*
Object - Oriented Programming 2022 @ FMI
Lecture #01, sample code
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>

struct Student
{
	// fields of the structure
	char id[8];
	char name[36];
	char program[24];
	int year;
	double averageGrades;
};

int main()
{
	Student me = { "01M1234", "Me", "Informatics", 1, 5.78 };

	// access to the fields using the operator .
	std::cout << me.id << std::endl;
	me.year++;

	strcpy(me.program, "Computer Science");
	std::cout << me.program << std::endl;

	const Student you = {"1", "You", "Mathematics", 4, 4.75};
	// you.year++; // error, the value cannot be modified

	// operations for input and output are not defined
	// std::cin >> me;
	// std::cout << me;

	// assignment
	me = you;
	std::cout << me.program << std::endl;

	return 0;
}