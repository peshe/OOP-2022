#include "Dictionary.h"
#include <iostream>

void Dictionary::copy(const Dictionary& other)
{
	this->size = other.size;
	this->records = new Record[other.capacity];
	this->capacity = other.capacity;

	for (int i = 0; i < size; i++)
	{
		this->records[i] = other.records[i];
	}
}

void Dictionary::resize()
{
	if (this->capacity * 2 > 500)
	{
		std::cout << "Maximum limit of records!" << std::endl;
	}
	else
	{
		this->capacity *= 2;
		Record* temp = new Record[this->capacity];

		for (int i = 0; i < this->size; i++)
		{
			temp[i] = this->records[i];
		}

		delete[] this->records;
		this->records = temp;
	}
}

void Dictionary::destroy()
{
	delete[] records;
}

Dictionary::Dictionary()
{
	this->records = new Record[3];
	this->size = 0;
	this->capacity = 0;
}

Dictionary::Dictionary(const Dictionary& other)
{
	copy(other);
}

Dictionary::Dictionary(const int capacity)
{
	this->capacity = capacity;
	this->records = new Record[capacity];
}

Dictionary& Dictionary::operator=(const Dictionary& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Dictionary::~Dictionary()
{
	destroy();
}

void Dictionary::addRecord(const char* word, const char* meaning)
{
	if (this->records == nullptr)
	{
		this->records = new Record[8];
		this->capacity = 8;
	}
	if (this->size + 1 == this->capacity)
	{
		resize();
	}

	Record newRecord(word, meaning);
	this->records[this->size++] = newRecord;
}

void Dictionary::print()
{
	for (int i = 0; i < this->size; i++)
	{
		this->records[i].printWord();
	}
}

int Dictionary::getSize() const
{
	return this->size;
}

int Dictionary::getCapacity() const
{
	return this->capacity;
}

const Record& Dictionary::find(const char* wordToFind) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (strcmp(this->records[i].getWord(), wordToFind) == 0)
		{
			return this->records[i];
		}
	}
}