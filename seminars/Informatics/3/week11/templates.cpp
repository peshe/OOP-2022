#include <iostream>
  
template <typename T>
void swap(T& a, T& b) {
    if(&a == &b) {
        return;
    }
    
    T temp = a;
    a = b;
    b = temp;
}
  
int main()
{
    double a = 5.6;
    double b = 7.8;
    swap<double>(a,b);
    
}