#include <iostream>

using namespace std;

class Point {
private:
    double x, y;
public:
    double getX() {
        return x;
    }
    
    double getY() {
        return y;
    }
    
    void setX(double newX) {
        x = newX;
    }
    
    void setY(double newY) {
        y = newY;
    }
    
    double dist(const Point& p2) {
        double dx = x - p2.x;
        double dy = y - p2.y;
        return sqrt(dx*dx + dy*dy);
    }
    
    double distFromOrigin() {
        Point origin;
        origin.x = 0;
        origin.y = 0;
        
        return dist(origin);
    }
}

int main()
{
    Point p1, p2;

    return 0;
}
