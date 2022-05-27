#include <iostream>
  
template <typename T>
T& max(T& a, T& b) {
    return (a > b) ? a : b;
}
  
int main()
{
    double a = 5.6;
    double b = 7.8;
    std::cout<< max<double>(a,b)<< std::endl;
}