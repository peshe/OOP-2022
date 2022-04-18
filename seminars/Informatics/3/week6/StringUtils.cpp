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
