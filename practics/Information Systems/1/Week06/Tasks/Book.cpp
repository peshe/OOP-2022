#include "Book.h"
#include <string>

void Book::copy(const Book& other) {
    if (other.authorName != nullptr)
    {
        this->authorName = new char[other.lenght + 1];
        for (int i = 0; i < other.lenght; ++i)
        {
            this->authorName[i] = other.authorName[i];
        }
        this->lenght = other.lenght;
        this->numberOfPages = other.numberOfPages;
    }
    else {
        this->authorName = nullptr;
        this->lenght = 0;
        this->numberOfPages = 0;
    }
}

void Book::erase() {
    if (this->authorName != nullptr)
    {
        delete[] this->authorName;
    }
}

Book::Book() {
    this->authorName = new char[1];
    this->authorName[0] = '\0';

    this->lenght = 0;
    this->numberOfPages = 0;
}

Book::Book(const char* authorName, unsigned lenght, const int& numberOfPages) {
    this->lenght = lenght;
    this->numberOfPages = numberOfPages;
    this->authorName = new char[lenght + 1];

    for (unsigned i = 0; i < lenght; ++i) {
        this->authorName[i] = authorName[i];
    }
}

Book::Book(const Book& other) {
    this->copy(other);
}

const Book& Book::operator=(const Book& other) {
    if (this != &other) {
        this->erase();
        this->copy(other);
    }

    return *this;
}

const char* Book::getAuthorName() const {
    return this->authorName;
}

const int Book::getNumberOfPages() const {
    return this->numberOfPages;
}

void Book::setNewAuthorName(const char* newAuthorName, unsigned lenght) {
    this->lenght = lenght;
    this->erase();
    this->authorName = new char[lenght + 1];

    for (unsigned i = 0; i < this->lenght; ++i) {
        this->authorName[i] = newAuthorName[i];
    }
}

void Book::setNeNumberOfPages(const int newNumberOfPages) {
    this->numberOfPages = numberOfPages;
}

Book::~Book() {
    this->erase();
}