#include <iostream>
#include <cassert>

template<class T = int>
class Stack
{
	T* arr;
	int size;
	int capacity;
public:

	Stack(int = 16);
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	~Stack();

	const T& top() const;
	void pop();
	void push(const T&);
	int getSize() const;
	bool isEmpty() const;

private:
	void deleteStack();
	void copyStack(const Stack<T>&);
	void resize();
};

template<class T>
Stack<T>::Stack(int capacity)
{
	this->arr = new T[capacity];
	this->size = 0;
	this->capacity = capacity;
}

template<class T>
Stack<T>::Stack(const Stack<T>& other)
{
	copyStack(other);
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		deleteStack();
		copyStack(other);
	}

	return *this;
}

template<class T>
Stack<T>::~Stack()
{
	deleteStack();
}

template<class T>
void Stack<T>::deleteStack()
{
	delete[] arr;
}

template<class T>
void Stack<T>::copyStack(const Stack<T>& other)
{
	this->arr = new T[other.capacity];
	this->size = other.size;
	this->capacity = other.capacity;

	for (int i = 0; i < size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

template<class T>
const T& Stack<T>::top() const
{
	assert(!isEmpty());
	return this->arr[size - 1];
}

template<class T>
void Stack<T>::pop()
{
	assert(!isEmpty());
	this->size--;
}

template<class T>
int Stack<T>::getSize() const
{
	return size;
}

template<class T>
bool Stack<T>::isEmpty() const
{
	return this->size == 0;
}

template<class T>
void Stack<T>::push(const T& value)
{
	if (size >= capacity)
	{
		resize();
	}

	this->arr[size] = value;
	size++;
}

template<class T>
void Stack<T>::resize()
{
	T* newArr = new T[2 * capacity];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = this->arr[i];
	}
	delete[] arr;
	this->capacity = 2 * capacity;
	this->arr = newArr;
}