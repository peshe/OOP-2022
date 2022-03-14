#include <iostream>

struct cordinates
{
	double x;
	double y;
};

cordinates midpoint(cordinates pointOne, cordinates pointTwo)
{
	cordinates midpoint;
	midpoint.x = (pointOne.x + pointTwo.x) / 2;
	midpoint.y = (pointOne.y + pointTwo.y) / 2;

	return midpoint;
}

void midpoint(double x1, double y1, double x2, double y2, double& resX, double& resY);

void taskCoordinates() {
	cordinates pointOne = {7, 5};
	cordinates pointTwo = {9, 11};

	cordinates result = midpoint(pointOne, pointTwo);

	std::cout << result.x << " " << result.y << std::endl;
}

enum Subjects {
	UNDEFINED = -1,
	LA,
	UP,
	DIS,
	AG,
	OOP,
	subjectsCount
};

const int MAX_GRADES_COUNT = 10;
const int FN_SIZE = 11;

struct Student {
	char fn[FN_SIZE];
	double grades[subjectsCount][MAX_GRADES_COUNT];
};

double avgGrade(const Student& student, Subjects subject) {
	int i = 0;
	double answer = 0;
	for (; student.grades[subject][i] != 0; i++) {
		answer += student.grades[subject][i];
	}
	return i ? answer / i : 2;
}

double avgGradeAll(const Student& student) {
	double result = 0;
	for(int i = UNDEFINED; i < subjectsCount; i++)
	{
		result += avgGrade(student, (Subjects) i);
	}
	return result / subjectsCount;
}

int maxAvgUspeh(Student* students, int size) {
	int maxIdx = 0;
	double maxAvgUspeh = avgGradeAll(students[0]);
	for (int i = 1; i < size; i++) {
		const double grade = avgGradeAll(students[i]);

		if (maxAvgUspeh < grade) {
			maxIdx = i;
			maxAvgUspeh = grade;
		}
	}
	return maxIdx;
}

void taskStudent() {
	Student students[] = { {"1", { {4, 2, 3} } }, {"2", { {4, 2, 4} } }, {"3", { {4, 6, 6} } } };

	const Student s = {};

	std::cout << avgGradeAll(s);
}
int main() {
	taskStudent();
}
