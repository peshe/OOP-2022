#include <iostream>
#include <cstring>

using namespace std;

// // Same class
// class Base {
// private:
//     int privateInteger;
// protected:
//     int protectedInteger;

//     void f() {
//         this->privateInteger
//     };
// };

// // Derived classes
// class A : public Base {
//     void f() {
//         this->protectedInteger;
//     }
// };

class FunctionOverload
{
public:
    // 1 параметър int
    void func(int x)
    {
        cout << "value of x is " << x << endl;
    }
    
    // 1 параметър double
    void func(double x)
    {
        cout << "value of x is " << x << endl;
    }
    
    // 2 параметъра
    void func(int x, int y)
    {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
    
    // това се вика автоматично при "сбор" на две комплексни числа
    Complex operator + (Complex const &obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() { cout << real << " + i" << imag << endl; }
};

class Base {
public:
    virtual void print()
    {
        cout << "print base class\n";
    }

    void show()
    {
        cout << "show base class\n";
    }
};

class Derived : public Base {
public:
    void print() override
    {
        cout << "print derived class\n";
    }

    void show()
    {
        cout << "show derived class\n";
    }
};

// asbstract class
class BaseAbstract {
    int x;
public:
    virtual void show() = 0;
    int getX() { return x; }
};

// Outside classes
int main() {
    FunctionOverload obj1;
    
    // Коя функция от трите ще се изпълни, зависи от това какви параметри подаваме
    // Това вече сме го говорили.
    obj1.func(7);
    
    obj1.func(9.132);
    
    obj1.func(85,64);

    Derived d;
    // d.print();

    Base* basePtr;
    Derived derived;
    basePtr = &derived;

    basePtr->print(); // runtime

    basePtr->show(); // compile
}