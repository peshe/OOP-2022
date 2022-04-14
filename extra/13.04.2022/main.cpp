#include <iostream>
#include <cstring>
#include <cstddef>
#include <fstream>

bool isDigit(char c) {
	return ('0' <= c && c <= '9');
}

class ISBN {
	static const unsigned ISBN_SIZE = 18;
	char number[ISBN_SIZE];
public:
	// алтернативен вариант - махате конструктора по подразбиране
	// и оставяте само конструктор с параметри, катo така задължавате потребителя
	// винаги да въвежда номер
	ISBN() {
		strcpy_s(number, ISBN_SIZE, "978-0-00-000000-0");
	}

	ISBN(const char* number) {
		if (strlen(number) + 1 != ISBN_SIZE)
		{
			throw std::exception("Wrong format, len!");
		}
		if (number[0] != '9' || number[1] != '7' || number[2] != '8')
		{
			throw std::exception("Wrong format, not 978!");
		}
		if (number[3] != '-' || number[5] != '-' || number[8] != '-' || number[16] != '-')
		{
			throw std::exception("Wrong dash format!");
		}

		std::size_t digits_indexes[] = {4, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17};

		for (size_t i = 0; i < sizeof(digits_indexes) / sizeof(int); i++)
		{
			if (isDigit(number[digits_indexes[i]]) == false)
			{
				throw std::exception("Not a digit!");
			}
		}
		strcpy(this->number, number);
	}

	bool operator==(const ISBN& other) const {
		return strcmp(number, other.number) == 0;
	}

	bool operator!=(const ISBN& other) const {
		//return this->operator==(other) == false;
		return !(*this == other);
	}

	void write(std::ostream& out) const {
		out.write(number, ISBN_SIZE);
	}

	static ISBN read(std::istream& in) {
		ISBN isbn;
		in.read(isbn.number, ISBN_SIZE);
		return isbn;
	}
};
class Book {
	char* name;
	char* author;
	double weight;
	ISBN isbn;
	void copy(const Book& other)
	{
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		author = new char[strlen(other.author) + 1];
		strcpy_s(author, strlen(other.author) + 1, other.author);
		weight = other.weight;
		isbn = other.isbn;
	}

	void destroy() {
		delete[] name;
		delete[] author;
	}
public:
	Book() {
		this->name = new char[1];
		this->name[0] = '\0';
		this->author = new char[1];
		this->author[0] = '\0';
		this->weight = 0;
		//this->isbn = ISBN();-- излишно
	}
    Book(const Book &other)
	{
		copy(other);
	}
	Book& operator=(const Book& other) {
		if (this != &other) {
			destroy();
			copy(other);
		}

		return *this;
	}

	~Book() {
		destroy();
	}

	double getWeight() const {
		return this->weight;
	}

	const ISBN& getISBN() const {
		return this->isbn;
	}

	static Book read(std::istream& in) {
		size_t name_len;
		in.read(reinterpret_cast<char*>(&name_len), sizeof(name_len));
		char* name = new char[name_len];
		in.read(name, name_len);

		size_t author_len;
		in.read(reinterpret_cast<char*>(&author_len), sizeof(author_len));
		char* author = new char[author_len];
		in.read(author, author_len);

		double weight;
		in.read(reinterpret_cast<char*>(&weight), sizeof(weight));

		Book book;
		book.name = name;
		book.author = author;
		book.weight = weight;
		book.isbn = ISBN::read(in);

		return book;
	}

	void write(std::ostream& out) const {
		size_t name_len = strlen(name) + 1;
		out.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len));
		out.write(name, name_len);
		size_t author_len = strlen(author) + 1;
		out.write(reinterpret_cast<const char*>(&author_len), sizeof(author_len));
		out.write(author, author_len);
		out.write(reinterpret_cast<const char*>(&weight), sizeof(weight));
		isbn.write(out);
	}
};

class Backpack
{
private:
	Book* books;
	std::size_t size;
	std::size_t capacity;

	double currentWeight;
	const double maxWeight;

	bool hasSpace(const Backpack& other)
	{
		return this->maxWeight >= other.currentWeight;
	}

	void copy(const Backpack& other)
	{
		this->capacity = other.capacity;
		this->size = other.size;
		this->currentWeight = other.currentWeight;
		this->books = new Book[other.capacity];
		for (size_t i = 0; i < other.size; i++)
		{
			this->books[i] = other.books[i];
		}

	}

	void erase()
	{
		delete[] books;
	}
	void resize()
	{
		this->capacity *= 2;

		Book* largerBooks = new Book[this->capacity];

		for (size_t i = 0; i < this->size; i++)
		{
			largerBooks[i] = books[i];
		}

		delete[] books;
		books = largerBooks;
	}

public:

	Backpack(const double maxWeight):maxWeight(maxWeight)
	{
		this->capacity = 8;
		this->size = 0;
		books = new Book[this->capacity];

		this->currentWeight = 0;
	}
	Backpack(const Backpack& other):maxWeight(other.maxWeight)
	{
		this->copy(other);
	}
	Backpack& operator=(const Backpack& other)
	{
		if (this != &other)
		{
			if (!hasSpace(other))
			{
				throw std::exception("Can NOT copy Backpack");
			}

			this->erase();
			this->copy(other);
		}
		
		return *this;
	}
	~Backpack()
	{
		this->erase();
	}

	void addBook(const Book& book)
	{
		if (this->maxWeight < this->currentWeight + book.getWeight())
		{
			throw std::exception("Book can NOT be added");
		}

		if (this->size >= this->capacity)
		{
			this->resize();
		}

		this->books[this->size] = book;
		this->size++;
		this->currentWeight += book.getWeight();
	}

	void removeBook(const ISBN& isbn) {
		for (size_t i = 0; i < size; i++)
		{
			if (this->books[i].getISBN() == isbn)
			{
				for (size_t k = i + 1; k < size; k++)
				{
					this->books[k - 1] = this->books[k];
				}
			}
		}
	}

	/*
	* Помислете как може да изнесете функциите read и write извън класа.
	* Какви функции ще направите в какви класове? 
	* Как тези класове ще достъпват член-данните, за да ги сериализират?
	*/

	void write(std::ostream& out) const {
		out.write(reinterpret_cast<const char*>(&maxWeight), sizeof(maxWeight));
		out.write(reinterpret_cast<const char*>(&size), sizeof(size));
		for (size_t i = 0; i < size; i++)
		{
			this->books[i].write(out);
		}
	}

	static Backpack read(std::istream& in) {
		double maxWeight = 0;
		in.read(reinterpret_cast<char*>(&maxWeight), sizeof(maxWeight));
		Backpack result(maxWeight);

		std::size_t size = 0;
		in.read(reinterpret_cast<char*>(&size), sizeof(size));

		for (size_t i = 0; i < size; i++) {
			Book newBook = Book::read(in);
			result.addBook(newBook);
		}
	}
};
int main() {
	Backpack backpack(5);

	backpack.addBook(Book());
	backpack.addBook(Book());

	std::ofstream out("test.bin", std::ios::binary);

	backpack.write(out);

	return 0;
}
