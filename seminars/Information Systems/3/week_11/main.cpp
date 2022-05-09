#include <iostream>
#include <cstring>

using namespace std;

class A
{
public:
  A() { 
    cout << "A's constructor called" << endl; 
  }

  void print() const {
    cout << "Hello, I am A" << endl;
  }

  ~A() {
    cout << "DESTRUCTOR A" << endl;
  }
};
  
class B
{
public:
  B() { 
    cout << "B's constructor called" << endl; 
  }

  void print() const {
    cout << "Hello, I am B" << endl;
  }

  ~B() {
    cout << "DESTRUCTOR B" << endl;
  }
};
  
class C: public B, public A  // Note the order
{
public:
  C() { 
    cout << "C's constructor called" << endl; 
  }

  ~C() {
    cout << "DESTRUCTOR C" << endl;
  }

  void print () { 
    A::print();
    B::print();
  }
};

int main()
{
    C c;
    return 0;
}