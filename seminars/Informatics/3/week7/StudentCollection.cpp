#include <iostream>
#include "StudentCollection.h"

StudentCollection::StudentCollection() :
	students(new Student[10]),
	size(0), 
	capacity(10)
{}

StudentCollection::StudentCollection(const StudentCollection& other) {
	copy(other, false);
}

StudentCollection& StudentCollection::operator=(const StudentCollection& other) {
	if (this != &other){
		copy(other);
	}
	return *this;
}

StudentCollection::~StudentCollection() {
	clean();
}

const Student& StudentCollection::getAt(int index) {
	if (!(index < size)) {
		std::cout << "index out of range. Size is " << size << std::endl;
		throw std::exception();
	}

	return students[index];
}

void StudentCollection::add(const Student& newStudent) {
	if (size >= capacity)
	{
		expand();
	}

	students[size] = newStudent;
	++size;
}

void StudentCollection::expand() {
	Student* temp = nullptr;
	try {
		temp = new Student[capacity * 2];
	} catch (std::bad_alloc) {
		std::cout << "allocation failed" << std::endl;
		return;
	}

	capacity *= 2;
	for (int i = 0; i < size; ++i) {
		temp[i] = students[i];
	}
	delete[] students;
	students = temp;
}

void StudentCollection::copy(const StudentCollection& other, bool withClean) {
	Student* temp = nullptr;
	try {
		temp = new Student[other.size];
	}
	catch (std::bad_alloc)
	{
		std::cout << "allocation failed"<< std::endl;
		return;
	}

	if (withClean) {
		clean();
	}

	size = other.size;
	capacity = other.capacity;
	students = temp;
	for (int i = 0; i < other.size; ++i) {
		students[i] = other.students[i];
	}
}

void StudentCollection::clean() {
	delete[] students;
	students = nullptr;
}
