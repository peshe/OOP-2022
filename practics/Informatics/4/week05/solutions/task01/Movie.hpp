#pragma once

class Movie
{
private:
    char* name;
    char* director;
    int length;

    void copy(const char* name, const char* director, const int length);
    void destroy();

public:
    Movie();
    Movie(const Movie& other);
    Movie(const char* name, const char* director, const int length);
    Movie& operator=(const Movie& other);
    ~Movie();
};