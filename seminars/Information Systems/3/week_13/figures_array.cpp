#include <iostream>

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

void printFigures(Figure* figure) {
    std::cout << figure->getName() << ": " << std::endl;
    std::cout << figure->perimeter() << std::endl;
    std::cout << figure->area() << std::endl;
}

// масив от фигури (абстрактно)
void printArea(Figure* figures[]) {
    int size = 3;
    for (int i = 0; i < size; i++) {
        double area = figures[i]->area();
        std::cout << area << std::endl;
    }
}

int main() {
    Figure* fig1 = new Rectangle(10, 20);
    Figure* fig2 = new Circle(12);
    Figure* fig3 = new Circle(155);

    // act as if its a normal array
    Figure** figures = new Figure*[3];
    figures[0] = fig1;
    figures[1] = fig2;
    figures[2] = fig3;

    printArea(figures);
}