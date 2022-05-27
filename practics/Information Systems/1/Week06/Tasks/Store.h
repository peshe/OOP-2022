#pragma once
#include <iostream>
#include "Book.h"

/*
* Задача 3:
Напишете програма, която има клас Book от задача 1 и клас Store, 
който има масив от книги. Нека клас Book е приятел на клас Store. 
Напишете метод, който има параметър обект от клас Book и ако страниците на книга са 
под 500 го добавя в масива с книги.
*/


class Book;
class Store {
private:
	Book* books;
	unsigned size;
	unsigned capacity;

	void copy(const Store& other);
	void erase();
	void resize();

public:
	Store(const Book* books, const unsigned size);

	Store(const Store& other);

	const Store& operator=(const Store& other);

	void addBook(const Book& book);

	~Store();
};
