#include <iostream>
#include <cstring>

#include "Movie.hpp"


void Movie::copy(const char* name, const char* director, const int length)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->director = new char[strlen(director) + 1];
    strcpy(this->director, director);
    this->length = length;
}

void Movie::destroy()
{
    delete[] this->name;
    delete[] this->director;
}

Movie::Movie()
{
    this->name = nullptr;
    this->director = nullptr;
    this->length = 0;
}

Movie::Movie(const Movie& other)
{
    this->copy(other.name, other.director, other.length);  
}

Movie::Movie(const char* name, const char* director, const int length)
{
    this->copy(name, director, length);
}

Movie& Movie::operator=(const Movie& other)
{
    if(this != &other)
    {
        this->destroy();
        this->copy(other.name, other.director, other.length);
    }

    return *this;
}

Movie::~Movie()
{
    this->destroy();
}