#pragma once

template<class T>
class Box {
private:
	T* arr;
	size_t size; //size_t
	size_t capacity;

	bool isOpen;

	void copy(const Box& other);
	void erase();
	void resize();
public:
	Box(bool isOpen);
	Box(const Box& other);
	Box& operator=(const Box& other);
	~Box();

	void pushElementInBox(const T& element);

	Box& operator+(const Box& other); //return new object
	Box& operator+=(const Box& other); //return modify this object
	Box& operator-(const Box& other);
	Box& operator-=(const Box& other);
};

template<class T>
void Box<T>::copy(const Box& other) {
	this->isOpen = other.isOpen;
	this->size = other.size;
	this->capacity = other.capacity;
	this->arr = new T[this->capacity];

	for (size_t i = 0; i < this->size; ++i) {
		this->arr[i] = other.arr[i];
	}
}

template<class T>
void Box<T>::erase() {
	delete[] this->arr;
}

template<class T>
void Box<T>::resize() {
	this->capacity *= 2;
	T* newArr = new T[this->capacity];

	for (size_t i = 0; i < this->size; ++i) {
		newArr[i] = this->arr[i];
	}

	erase();
	this->arr = newArr;
}

template<class T>
Box<T>::Box(bool isOpen) {
	this->isOpen = isOpen;
	this->capacity = 8;
	this->size = 0;
	this->arr = new T[this->capacity];
}

template<class T>
Box<T>::Box(const Box& other) {
	this->copy(other);
}

template<class T>
Box<T>& Box<T>::operator=(const Box& other) {
	if (this != &other) {
		erase();
		copy(other);
	}

	return *this;
}

template<class T>
Box<T>::~Box() {
	erase();
}

template<class T>
void Box<T>::pushElementInBox(const T& element) {
	if (!this->isOpen) {
		std::cout << "The box is close\n";
		return;
	}

	if (this->capacity <= this->size) {
		resize();
	}

	this->arr[size++] = element;
}

template<class T>
Box<T>& Box<T>::operator+(const Box& other) {
	Box<T> newBox(this->isOpen);
	size_t smallSize = 0;
	if (this->size > other.size) {
		smallSize = other.size;
	}
	else {
		smallSize = this->size;
	}

	for (size_t i = 0; i < smallSize; ++i) {
		newBox.arr[i] = this->arr[i] + other.arr[i];
	}

	return newBox;
}

template<class T>
Box<T>& Box<T>::operator+=(const Box& other) {
	*this = *this + other;

	return *this;
}

template<class T>
Box<T>& Box<T>::operator-(const Box& other) {
	Box<T> newBox(this->isOpen);
	size_t smallSize = 0;
	if (this->size > other.size) {
		smallSize = other.size;
	}
	else {
		smallSize = this->size;
	}

	for (size_t i = 0; i < smallSize; ++i) {
		newBox.arr[i] = this->arr[i] - other.arr[i];
	}

	return newBox;
}

template<class T>
Box<T>& Box<T>::operator-=(const Box& other) {
	*this = *this - other;

	return *this;
}
