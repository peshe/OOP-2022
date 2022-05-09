#include <iostream>
#include <fstream>

class Point
{
private:
   int x, y;
public:
   Point& operator++() {
       this->x++;
       this->y++;
       return *this;
   }
};

int main() {
    
}