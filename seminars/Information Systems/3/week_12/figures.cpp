#include <iostream>
#include <cstring>

class Figure {
public:
    virtual double perimeter() = 0;
    virtual double area() = 0;
    virtual const char* getName() = 0;
};

class Rectangle : public Figure {
private:
    double height, width;
    const char name[10] = "Rectangle";
public:   
    Rectangle(double height, double width) {
        this->height = height;
        this->width = width;
    }

    double perimeter() override {
        return 2 * height + 2 * width;
    }

    double area() override {
        return height * width;
    }

    const char* getName() override {
        return this->name;
    }
};

class Circle : public Figure {
private:
    double radius;
    const char name[7] = "Circle";
public:
    Circle(double radius) {
        this->radius = radius;
    }

    double perimeter() override {
        return 2 * 3.14 * radius;
    }

    double area() override {
        return 3.14 * radius * radius;
    }

    const char* getName() override {
        return this->name;
    }
};

void printFigure(Figure* figure) {
    std::cout << figure->getName() << ": " << std::endl;
    std::cout << figure->perimeter() << std::endl;
    std::cout << figure->area() << std::endl;
}

int main() {
    Figure* rect = new Rectangle(10, 30);
    Figure* circle = new Circle(25);
    
    printFigure(rect);
    printFigure(circle);
}