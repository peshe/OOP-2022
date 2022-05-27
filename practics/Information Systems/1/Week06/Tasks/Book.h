#pragma once
#include "Store.h"

/*
* Задача 1:
Напишете програма, която има клас Book с има на автор(масив от символи с различна дължина) 
и брой страници. 
Класът има функции:
- които връщат името на автора и дължината 
- които променят името на автора и дължината
*/
class Store;
class Book {
private:
	char* authorName;
	int numberOfPages;
	unsigned lenght;

	void copy(const Book& other);
	void erase();

public:
	Book();

	Book(const char* authorName, unsigned lenght, const int& numberOfPages);

	Book(const Book& other);

	const Book& operator=(const Book& other);

	const char* getAuthorName() const;
	const int getNumberOfPages() const;

	void setNewAuthorName(const char* newAuthorName, unsigned lenght);
	void setNeNumberOfPages(const int newNumberOfPages);

	~Book();

	friend class Store;
};
