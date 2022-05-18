#include "Store.h"

void Store::copy(const Store& other) {
    this->books = new Book[other.capacity];
    for (int i = 0; i < other.size; ++i)
    {
        this->books[i] = other.books[i];
    }
    this->size = other.size;
    this->capacity = other.capacity;
}

void Store::erase() {
    delete[] this->books;
}

void Store::resize() {
    this->capacity *= 2;
    Book* newBookArray = new Book[this->capacity];

    for (int i = 0; i < this->size; ++i)
    {
        newBookArray[i] = this->books[i];
    }

    this->erase();
    this->books = newBookArray;
}

Store::Store(const Book* books, const unsigned size) {
    this->capacity = size + 16;
    this->books = new Book[this->capacity];

    this->size = size;

    for (unsigned i = 0; i < size; ++i) {
        this->books[i] = books[i];
    }
}

Store::Store(const Store& other) {
    this->copy(other);
}

const Store& Store::operator=(const Store& other) {
    if (this != &other) {
        this->erase();
        this->copy(other);
    }

    return *this;
}

void Store::addBook(const Book& book) {
    if (book.numberOfPages < 500) {
        if (this->capacity < this->size + 1) {
            this->resize();
        }

        this->books[size++] = book;
    }
    else {
        std::cout << "Book is with more than 500 pages" << std::endl;
    }
}

Store::~Store() {
    erase();
}