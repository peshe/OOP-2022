### Класове
Клас дефинираме по същия начин като структура:

```c++
class Person
{
    char name[50];
    unsigned age;
};
```

### Модификатори за достъп (Access modifiers)
- `public`, `private`, `protected`
- Модификаторът за достъп на класовете по пдразбиране е `private`, а на структурите - `public`. Това е и 
единствената съществена разлика между тях. По тази причина класът `Person`, дефиниран по-горе, **няма да има** видими извън него член-данни.

### Методи (член-функции)
- Функции, дефинирани в тялото на класа
- Специалното за тях е, че имат "скрит" указател към обекта, който ги извиква - `this`. Използваме го експлицитно, когато имаме еднакви имена на аргументите на функциите и член-данните на обекта
- Препоръчително е всички методи, които не променят обекта, да бъдат константи
   
   > Всички константни методи правят указателя `this` константен => в тялото им можем да извикваме само други константни методи. 

 ```c++
class Point
{
public:
    bool isInFirstQuadrant() const
    {
        return x >= 0 && y >= 0;
    }
    
    void revert()
    {
        x = -x;
        y = -y;
    }

private:
    int x;
    int y
};
 ```
    
### Конструктори 
- Методи, които се извикват, когато създаваме обект от класа
- Името им е същото като името на класа
- Могат да приемат всякакви аргументи, които ни трябват за създаването на обекта (най-често са стойностите на някои/всички от член-данните)
- Когато не дефинираме конструктор в тялото на класа **се създава** конструктор по подразбиране, който инициализира всички член-данни с тези стойности, които сме им задали по подразбиране
- Когато дефинираме конструктор в тялото на класа **не се създава** констрктор по подразбиране
- Препоръчително е да използваме инициализиращ списък, вместо да присвояваме в тялото на класа

```c++
class Person
{
public:
    Person() = default;
    Person(unsigned age, const char* name) : age_{age}
    {
        std::strcpy(name_, name);
    }
private:
    char name[50]_;
    unsigned age_;
};
```

```c++
// GOOD
class Person
{
public:
    bool is_years_old(unsigned age) const
    {
        return age == age_;
    }
private:
    char name_[50];
    unsigned age_;
};
```

```c++
// NOT SO GOOD
class Person
{
public:
    bool is_years_old(unsigned age) const
    {
        return age == this->age;
    }
private:
    char name[50];
    unsigned age;
};
```

 ```c++
#include <iostream>

class Test 
{
public:
    Test()
    {
        std::cout << "Object is created" << std::endl;
    }
  
    ~Test()
    {
        std::cout << "Object is destroyed" << std::endl;
    }

private:
    int a;
    int b;
};

int main()
{
    {
        Test t;// Object is created 
        {
            Test t2; // Object is created 

        } // Object is destroyed (t2)

    } //Object is destroyed (t)
}
 ```

### Selectors & Мutators (Getters & Setters)
1. Методи, чието предназначение е да дават "безопасен" начин за употреба на нашите класове. Чрез тях реализираме принципа за **енкапсулация**. 
2. Всички член-данни, чиято стойност желаем да е видима публично, expose-ваме чрез selector-и. Препоръчително е selector-ите да са константи функции.
3. Всички член-данни, чиято стойност желаем да може да се променя публично, expose-ваме чрез mutator-и.

```c++
class Person
{
public:
    // selectors
    unsigned get_age() const
    {
        return age_;
    }
    const char* get_name() const
    {
        return name_;
    }

    // mutators
    void set_age(unsigned age)
    {
        age_ = age;
    }
    void set_name(const char* name)
    {
        std::strcpy(name_, name);
    }
private:
    char name_[50];
    unsigned age_;
};
```
# Разделна компилация. Абстракция.

## Разделна компилация.

![enter image description here](https://gamedevunboxed.com/wp-content/uploads/2019/08/image.png)

Една програма на С++ може да бъде разбита в множество файлове, които се **компилират независимо един от друг**, т.е. осъществява се **разделна компилация**. В резултат на компилацията се получават няколко **обектни файла** (файлове с разширение **.obj**). Изпълнимият код напрограмата (файл с разширение .ехе) се получава след свързване на обектните файлове (**Linking**).

За да се възполваме максимално от разделната компилация, разделяме класовете на **.h** и **.cpp** файлове. Навсякъде където ще работим с класа, ще включваме **само .h файла.** По този начин, ако променим реализацията на някоя от функциите на класа, ще се **прекомпилира само този файл**.

## Абстракция
Пример за **лоша абстракция**:

```c++
struct Triangle
{
	int x1;
	int y1;
	
	int x2;
	int y2;

	int x3;
	int y3;
};

int getPer(const Triangle& t)
{
	return
	 sqrt( (t.x1-t.x2)*(t.x1-t.x2) + (t.y1-t.y2)*(t.y1-t.y2) + 
	 sqrt( (t.x2-t.x3)*(t.x2-t.x3) + (t.y2-t.y3)*(t.y2-t.y3) + 
	 sqrt( (t.x3-t.x1)*(t.x3-t.x1) + (t.y3-t.y1)*(t.y3-t.y1); 
}
 ```
 Пример за **по-добра абстракция**:
 ```c++
struct Point
{
	int x;
	int y
	double getDistTo(const Point& other)
	{
		return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
	}
};

struct Triangle
{
	Point p1;
	Point p2;
	Point p3;
};

int getPer(const Triangle& t)
{
	return t.p1.getDistTo(t.p2) + t.p2.getDistTo(t.p3) + t.p3.getDistTo(t.p1);
}
 ```