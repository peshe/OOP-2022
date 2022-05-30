# Упражнение 14

## Какво правихме предния път?
- Наследяване + Полиморфизъм (Figures)
- Шаблони на функции



## Декларация за шаблон на клас:


Подобно на шаблоните за функции, можем да използваме templates за класове, за да създадем един клас да работи с различни типове данни.
Class templates са полезни, тъй като могат да направят нашия код по-кратък и по-управляем.

Шаблонът на класа започва с ключовата дума template, последван от параметър(и) на шаблона вътре в <>, което е последвано от декларацията на класа.

Пример:
```c++
template <class T>
class className 
{
  private:
    T var;
    //...
  public:
    T functionName(T arg);
    //...
};
```

В горната декларация **T** е аргументът на шаблона, който е заместител за използвания тип данни, а class е ключова дума.
Вътре в тялото на класа, член данната var и резултатът върнат от метода functionName() са от тип T.

## Създаване на обект на шаблон за клас:


След като сме декларирали и дефинирали шаблон на клас, можем да създадем обекти от този клас в други класове или функции (като функцията main()) със следния синтаксис
```c++
className<dataType> classObject;
```

Необходимо е експлицитно да означим типа на темплатния параметър в <> преди името на обекта.

Пример:

```c++
className<int> classObject;

className<float> classObject;

className<string> classObject;
```

Пример за template class :

```c++
// Class template
template <class T>
class Number {
   private:
    // Variable of type T
    T num;

   public:
    Number(T n) : num(n) {}   // constructor

    T getNum() {
        return num;
    }
};

int main() {

    // create object with int type
    Number<int> numberInt(7);

    // create object with double type
    Number<double> numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}
```

Изход:

```c++
int Number = 7
double Number = 7.7

от горния пример 
//Error
Number numberInt(7);
Number numberDouble(7.7);
```

## Дефиниране на член на клас извън шаблона на класа:

Да предположим, че трябва да дефинираме метод извън шаблона на класа. Можем да направим това със следния код:

```c++
template <class T>
class ClassName 
{
    //...

    // Function prototype
    returnType functionName();
};

// Function definition
template <class T>
returnType ClassName<T>::functionName() 
{
    //...
}
```

Забележете, че template <class T> се повтаря, когато дефинираме функцията извън класа. Това е необходимо и е част от синтаксиса.

## Шаблони за класове с множество параметри:


В C++ можем да използваме множество параметри на шаблона и дори да използваме аргументи по подразбиране за тези параметри по следния начин:

```c++
template <class T, class U, class V = int>
class ClassName 
{
  private:
    T member1;
    U member2;
    V member3;
    //...
  public:
    //...
};
```

Пример:
  
```c++
template <class T, class U, class V = char>
class ClassTemplate 
{
   private:
    T var1;
    U var2;
    V var3;

   public:
    ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}  // constructor

    void printVar() 
    {
        cout << "var1 = " << var1 << endl;
        cout << "var2 = " << var2 << endl;
        cout << "var3 = " << var3 << endl;
    }

    //...
};

int main() 
{
   
    ClassTemplate<int, double> obj1(7, 7.7, 'c');
    cout << "obj1 values: " << endl;
    obj1.printVar();

    
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
    cout << "\nobj2 values: " << endl;
    obj2.printVar();

    //...
}
```
  
Изход:
```
obj1 values: 
var1 = 7
var2 = 7.7
var3 = c

obj2 values: 
var1 = 8.8
var2 = a
var3 = 0
```
  
## Темплейти (templates) и разделна компилация:


Нека имаме следната програма:

array.h file:
```c++
// .. header guards / pragma once
template <class T>
class Array
{
   private:
        T *m_list;
        //...

   public:
        Array() //default constructor
        {
           m_list = nullptr;
          ///...
        }


        //...

        ~Arrary()
        {
            delete[] m_list;
            m_list = nullptr;
        }

      //undefined functions

       T getElement(const int pos); // returns element on current position 
};
```
  
array.cpp file :

```c++
include "array.h"

//...

template <class T>
T Array<T>::getElement(const int pos)
{ 
    return m_list[pos]; 
}

main.cpp file:
#include "array.h"
#include <iostream>


int main()
{
    Array<int> int_array;
    Array<double> double_array;

   std::cout << int_array.getElement(2) <<"\n";
   std::cout << double_array.getElement(3) << "\n";
}
```
  
Когато компилираме нашата програма, първо препроцесора копира темплейтната декларация от header файла в main файла.
В main сме създали обекти  :  Array< int >  и Array< double > ,
поради което се съдават 2 различни дефиниции на класа Array - за (int)  и за (double)
!Забележете до този момент дефинициите на функциите Array< int >::getElement(const int pos) и Array< double >::getElement(const int pos) в main файла още липсват , но компилатора компилира main файла без проблем.
В същото време файла array.cpp ,който съдържа дефиницията на Array< T >::getElement() се компилира без проблем, без да създава версии за int и double .
Припомнете си (cpp файловете се компилират поотделно всеки) - array.cpp не знае за създадените обекти в main файла.
По време на фазата на свързване (linking phase) се появяват грешки , поради липсващите дефиниции на функциите за int и за double.


Има различни начини за корекция на този проблем:

 1. дефиниране на класа и на методите му във header файла
    
 2. записването на дефинициите в .inl file
    
 3. #include .cpp включването на cpp файла в main.cpp (! не е препоръчително)
 
 4. дефинирането на методите с конкретните типове които ще ползвате след това (! не е препоръчително)