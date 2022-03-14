#include<iostream>
#include<math.h>

using std::cin;
using std::cout;
using std::endl;

const size_t SIZE = 4;

struct Point {

	int x;
	int y;
};

void readPoint(Point& point) {

	cout << "Enter coordinates of the point:";
	cin >> point.x >> point.y;
}

void printPoint(const Point& point) {

	cout << '(' << point.x << ", " << point.y << ")\n";
}

double distToCenter(const Point& point) {

	return sqrt(point.x * point.x + point.y * point.y);
}

double distBetweenTwoPoints(const Point& point1, const Point& point2) {

	return sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}

void readArrayOfPoints(Point points[SIZE]) {

	for (size_t i = 0; i < SIZE; ++i) {
		readPoint(points[i]);
	}
}

void printArrayOfPoints(Point points[SIZE]) {

	for (size_t i = 0; i < SIZE; ++i) {
		printPoint(points[i]);
	}
}

void printArrayOfPointsWithPointers(Point* start, Point* end) {

	for (Point* point = start; point != end; ++point) {
		cout << '(' << point->x << ", " << point->y << ")\n";
	}
}

int main() {

	Point p1;
	readPoint(p1);
	cout << "Distance to center:" << distToCenter(p1) << endl;

	Point p2 = { 2, 3 };
	cout << "Distance between two points:" << distBetweenTwoPoints(p1, p2) << endl;

	Point p3 = { 4, 7 };
	Point p4 = { 10, 12 };

	Point pointsArr1[SIZE] = { p1, p2, p3, p4 };
	printArrayOfPoints(pointsArr1);

	Point pointsArr2[SIZE] = { { 1, 2 }, { 2, 3 }, { 7, -1 }, { -5, 1 } };
	printArrayOfPointsWithPointers(pointsArr2, pointsArr2 + SIZE);

	Point pointsArr3[SIZE];
	readArrayOfPoints(pointsArr3);
	printArrayOfPointsWithPointers(pointsArr3, pointsArr3 + SIZE);

    return 0;
}
