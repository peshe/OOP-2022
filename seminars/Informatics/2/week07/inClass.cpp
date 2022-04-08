#include<cstddef>
#include<iostream>
class Set
{
private:
	int* elements;
	std::size_t capacity;
	std::size_t size;
	void resize() {
		this->capacity *= 2;
		int* new_el = new int[capacity];
		for (std::size_t i = 0; i < size; ++i)
		{
			new_el[i] = elements[i];
		}
		delete[] elements;
		elements = new_el;
	}
	bool contains(int el) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (elements[i] == el) {
				return true;
			}
		}
		return false;
	}
public:
	Set()
	{
		std::cout << "Set()\n";
		capacity = 8;
		size = 0;
		elements = new int[capacity];
	}
	Set(const Set& other)
	{
		std::cout << "Set(constSet&)\n";
		this->capacity = other.capacity;
		this->size = other.size;
		this->elements = new int[this->capacity];
		for (std::size_t i = 0; i < other.size; ++i)
		{
			this->elements[i] = other.elements[i];
		}
	}
	~Set()
	{
		delete[] elements;
	}
	void add_element(const int el) {
		if (size + 1 >= capacity){
			resize();
		}
		if (!contains(el))
		{
			elements[size] = el;
			size++;
		}
	}
	bool operator==(const Set& other) const
	{
		if (this->size != other.size)
		{
			return false;
		}
		for (std::size_t i = 0; i < other.size; ++i)
		{
			if (this->contains(other.elements[i]) == false)
			{
				return false;
			}
		}
		return true;
	}
	bool operator!=(const Set& other) const
	{ 
		//return (*this == other) == false;
		return !operator==(other);
	}
	Set& operator+=(const Set& other)
	{
		for (std::size_t i = 0; i < other.size; ++i)
		{
			this->add_element(other.elements[i]);
		}
		return *this;
	}
	Set operator+(const Set& other)
	{
		Set result(*this);
		result += other;
		return result;
	}
};

int main() {
	Set a, b;
	std::cout << "------------\n";
	Set c = a + b;
}
/*

## Set
Дефинирайте клас Set, които имплементира математическо множество от елементи. Класът да има следната функционалност":

*	оператор ==, който да връща истина тогава и само тогава когато всеки елемент на едното множество се съдържа в другото.
*	оператор + и +=, които да извършват операцията обединение на две множества
*	оператор * и *=, които да извършват операцията сечение на две множества
*	оператор - и -=, които да извършват операцията разлика на две множества
*	оператор <<, който да извежда множеството в поток (cout << aSet << endl;)

*/
