#include<iostream>
using namespace std;
  
class A
{
protected:
  int x;
public:
    A() { cout << " A() default " << endl; }    
    void setX(int i) {x = i;}
    void print() { cout << x << endl; }
};
  
class B : virtual public A
{
public:
  B()  { setX(10); } // x = 10 завинаги
};
  
class C : virtual public A  
{
public:
  C()  { setX(20); } // х = 20 завинаги
};
  
class D: public C, public B {
public:
    void print() {
        B::print();
        C::print();
    }

    void getX() {
        cout << B::x << endl;
        cout << C::x << endl;
    }
};
  
int main()
{
    D d;
    d.print();
    d.getX();
    return 0;
}