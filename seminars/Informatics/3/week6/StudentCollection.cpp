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
	capacity *= 2;
	Student* temp = new Student[capacity];
	for (int i = 0; i < size; ++i) {
		temp[i] = students[i];
	}
	delete[] students;
	students = temp;
}

void StudentCollection::copy(const StudentCollection& other, bool withClean) {
	if (withClean) {
		clean();
	}

	size = other.size;
	capacity = other.capacity;
	students = new Student[size];
	for (int i = 0; i < size; ++i) {
		students[i] = other.students[i];
	}
}

void StudentCollection::clean() {
	delete[] students;
	students = nullptr;
}
