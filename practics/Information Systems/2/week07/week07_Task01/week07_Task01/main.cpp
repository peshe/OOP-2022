#include <iostream>
#include <cstring>

#include "Dictionary.h"
#include "Record.h"

int main()
{
	Dictionary d;
	char inputWord[50];
	char inputMeaning[50];

	std::cin.getline(inputWord, 50);
	std::cin.getline(inputMeaning, 50);

	d.addRecord(inputWord, inputMeaning);

	std::cin.getline(inputWord, 50);
	std::cin.getline(inputMeaning, 50);

	d.addRecord(inputWord, inputMeaning);

	Record fin = d.find("apple");

	fin.printWord();
	return 0;
}