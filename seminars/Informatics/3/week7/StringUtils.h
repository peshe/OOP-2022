#pragma once
class StringUtils
{
public:
	int strlen(const char* str);
	void strcpy(char* destination, const char* source);
	void dynamicSet(char*& destination, const char* source, bool withCopy = false);
};

