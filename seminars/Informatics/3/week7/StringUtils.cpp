#include <exception>
#include <iostream>
#include "StringUtils.h"

int StringUtils::strlen(const char* str)
{
	int len = 0;
	while (str[len++] != '\0') {}
	return len;
}

void StringUtils::strcpy(char* destination, const char* source)
{
	int len = 0;
	for (; source[len] != '\0'; ++len) {
		destination[len] = source[len];
	}
	destination[len] = '\0';
}

void StringUtils::dynamicSet(char*& destination, const char* source, bool withCopy)
{
	char* temp = nullptr;
	try {
		temp = new char[strlen(source) + 1];
	} catch (std::bad_alloc) {
		std::cout << "allocation failed" << std::endl;
		return;
	}

	if (withCopy) {
		delete[] destination;
	}
	destination = temp;

	strcpy(destination, source);
}
