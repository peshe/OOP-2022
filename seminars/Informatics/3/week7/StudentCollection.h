#pragma once

#include "Student.h"

class StudentCollection
{
private:
	Student* students;
	int size;
	int capacity;

	void expand();
	void copy(const StudentCollection& other, bool withClean = true);
	void clean();
public:
	StudentCollection();
	StudentCollection(const StudentCollection& other);
	StudentCollection& operator=(const StudentCollection& other);
	~StudentCollection();


	const Student& getAt(int index);
	void add(const Student& newStudent);
};

