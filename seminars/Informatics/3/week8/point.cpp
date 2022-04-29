#include <iostream>

class Point {
    double x;
    double y;
public:
    Point(double x, double y): x(x), y(y) {}
    
    void print(std::ostream& out = std::cout) const {
        out<< "("<< x<< ", "<< y<< ")";
    }
    
    Point operator-() const {
        return Point(-x, -y);
    }
    
    Point operator-(const Point& other) const {
        return *this + -other;
    }
    
    Point operator*(double lambda) {
        return Point(lambda*x, lambda*y);
    }
    
    friend Point operator+(const Point& p1, const Point& p2);
};

Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
    p.print(out);
    return out;
}

int main() {
    Point p1(2,3), p2(4,5);
    std::cout<< p1<< " + "<< p2<< " = "<< p1+p2<< std::endl;
    std::cout<< "-"<< p1<< " = "<< -p1<< std::endl;
    std::cout<< p2<< " - "<< p1<< " = "<< p2-p1<< std::endl;
    std::cout<< 3<< " * "<< p1<< " = "<< 3*p1<< std::endl;
}