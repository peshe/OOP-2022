# Седмица 10 - Множествено наследяване. Виртуални базови класове

Hierarchical Inheritance:
=

Ако повече от един клас наследяват базовия клас, това наследяване е известно като йерархично наследяване. При йерархично наследяване всички характеристики, които са общи в класове(деца), са включени в базовия клас.

пример:
```
class base_class 
{
    //...
};
class first_derived_class: public base_class 
{
    //...
};

class second_derived_class: public base_class 
{
    //...
};

class third_derived_class: public base_class 
{
    //...
};
```

пример:
```
// base class
class Animal 
{
   public:
    void info() {
        cout << "I am an animal." << endl;
    }
};

// derived class 1
class Dog : public Animal 
{
   public:
    void bark() {
        cout << "I am a Dog. Woof woof." << endl;
    }
};

// derived class 2
class Cat : public Animal 
{
   public:
    void meow() {
        cout << "I am a Cat. Meow." << endl;
    }
};
```

Multilevel Inheritance:
=

В C++ не само можете да наследите базов клас, но можете и да наследите клас, който вече е наследил друг. Тази форма на 
наследяване се нарича multilevel inheritance

```
class A 
{
    //...
};
class B: public A 
{
    //...
};
class C: public B 
{
    //...
};
```

клас B наследява базовия клас A , а клас C наследява Derived класа B.

пример:
```
class A {
    public:
      void display() {
          cout<<"Class A content.";
      }
};

class B : public A {};

class C : public B {};

int main() {
    C obj;
    obj.display();
    return 0;
}

output: Class A content.
```

Компилаторът първо търси функцията display() в клас C. Тъй като функцията не съществува там, той търси функцията в клас B (тъй като C наследява B).
Функцията не съществува и в B, така че компилаторът я търси в клас A (тъй като B наследява от A)

Multiple Inheritance:
=

В C++ един клас може да има повече от един родител(да наследява повече от един клас), т.е, клас C да наследява както клас A така и клас B.

```
class A 
{
    //...
};
class B: 
{
    //...
};
class C: public A , public B 
{
    //...
};
```

Ambiguity in Multiple Inheritance:
=

Най-очевидният проблем с множественото наследяване възниква при преизползването на функции. Да предположим, че два базови класа имат една и съща функция, която не е презаписана в наследяващия клас.(Следващия път ще говорим повече за polymorphism)
Ако се опитаме да извикаме функцията с помощта на обекта на наследяващия клас, компилаторът показва грешка. Това е, защото компилаторът не знае коя функция да извика.

```
class base1 
{
  public:
      void someFunction( ) {....}  
};
class base2 
{
    void someFunction( ) {....} 
};
class derived : public base1, public base2 {};

int main() 
{
    derived obj;
    obj.someFunction() // Error!  
}
```

Този проблем може да бъде решен, като се каже изрично от кой клас да бъде използвана дадената функция.

```
int main() 
{
    obj.base1::someFunction( );  // Function of base1 class is called
    obj.base2::someFunction();   // Function of base2 class is called.
}
```

Virtual base class:
=


Виртуалните базови класове се използват при виртуалното наследяване, за да се предотврати появата на множество еднакви инстанции в наследяващия клас от базовия.
На много места ще чуете за диамантения пробелм (The Diamond Problem).

пример:
Нека имаме ситуацията, в която клас B  и калс C наследяват клас A. Сега нека клас D наследява клас B и клас C. 
Когато искаме да достъпим член данна/метод от клас A, чрез обект от клас D, възниква объркване коя член данна/метод да бъде извикат(наследения/та от клас B или наследения/та от клас C).Тази неяснота обърква компилатора и възниква грешка.

```
class A 
{
public:
    void show()
    {
        cout << "Class A \n";
    }
};
  
class B : public A 
{
    //...
};
  
class C : public A 
{
    //...
};
  
class D : public B, public C 
{
    //...
};
  
int main()
{
    D object;
    object.show();
}
```

**Как да се справим с този проблем?**

За да се справим с объркването, когато клас A се наследява от клас B, и клас C, той се декларира като виртуален базов клас чрез поставяне на ключова дума virtual.
Ключовата дума virtual може да бъде записана преди или след индентификатора за достъп.

```
Вариант 1:
class B : virtual public A 
{
    //...
};
```
```
Вариант 2:
class C : public virtual A
{
    //...
};
```

примeр:
```
class A 
{
public:
    void show()
    {
        cout << "Class A \n";
    }
};
  
class B : public virtual A 
{
};
  
class C : public virtual A 
{
};
  
class D : public B, public C 
{

};
  
int main()
{
    D object;
    object.show();
}
```

По този начин не възниква грешка.(има само една инстанция на метода show()).

Обяснение: Класът A има само един метод show(), който е публичен. Този клас се наследява от клас B и клас C. Сега клас B и клас C стават виртуалени базови класове и не се прави дублиране на метода.
