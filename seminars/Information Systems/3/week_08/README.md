# Упражнение 8

## Какво правихме предния път?
- move семантика
- friend класове/методи
- dynamic array 2.0

## Предефиниране на оператори

До сега сме загатнали темата за предифиниране на оператори, когато научихме какво е голяма четворка.
В голямата четворка един от компонентите беше `<клас>& operator=(const <клас>& other)`. Именно това наричаме **предефиниране на оператор**. Целта на предифинирането е да можете да си създадете custom логика върху операторите, а това прави кода ви по-елегантен и по-лесно четим. От към функционалност също прави нещата много по-добри - например ако искате да съберете две времена ще бъде много по-готино да използвате нещо от сорта на:
```c++
    Time t1(22,30,30);
    Time t2(4,25,47);

    Time sum = t1 + t2;
    // или
    std::cout << t1 + t2 << std::endl;

    // 22:30:30 + 04:25:47
    // резултат: 02:56:17
```

### Оператор `++` и `--` пример:

Припомняме си, че  можем да викаме операторите `++` и `--` по два начина, още познати като postfix и prefix (`++i` и `i++`)

```c++
class Point
{
public:
   // деклариране на двата типа ++
   Point& operator++();       // point++
   Point operator++(int);     // ++point

   // деклариране на двата типа --
   Point& operator--();       // point--
   Point operator--(int);     // --point

   // Define default constructor.
   Point() { 
       this.x = 0;
       this.y = 0; 
    }

   // Define accessor functions.
   int x() { 
       return this.x; 
    }
   int y() { 
       return this.y; 
    }
private:
   int x, y;
};
```

Съответно имплементираме общо `4 функции` за всеки оператор + за postfix и prefix вариантите на този оператор.

```c++
Point& Point::operator++()
{
   this.x++;
   this.y++;
   return *this;
}

Point Point::operator++(int)
{
   Point temp = *this;
   ++*this;
   return temp;
}

Point& Point::operator--()
{
   this.x--;
   this.y--;
   return *this;
}

Point Point::operator--(int)
{
   Point temp = *this;
   --*this;
   return temp;
}
```

### Ще дефинираме всички оператор към вече създадения ни `DynamicArray`.

Освен операторите `=`, `==`, `!=`, които вече сме разгледали (да си ги припомним първо), днес ще разгледаме още примери за предефиниране на оператори и ползите им.

```c++
bool operator==(const DynamicArray& other);
bool operator!=(const DynamicArray& other); 
```




### Оператор `+` и `-`

```c++
DynamicArray<T> operator+(const DynamicArray& other);
```

### Оператор `[]`

```c++
int& operator [](int i);
const int& operator [] (int i) const;
```



### Оператор `+=` и `-=`

```c++
DynamicArray<T>& operator +=(const DynamicArray& other);
```

### ostream & fstream

В C++ можем да въвеждаме и извеждаме вградените типове данни, използвайки операторите  >> и  <<.
Операторите за въвеждане и извеждане също могат да бъдат предефинирани, за да можем да ги използваме за създадените от нас типове.

```c++
class A {
    friend ostream &operator << (ostream& output, A& a);
    friend ifstream &operator >> (fstream& input, A& a);
};
```

Когато предефинираме тези оператори пишем функцията friend

При тези оператори, първият параметър е поток. Тъй като нямате достъп до обекта на потока (не можем да го променяте), функцията не може да бъде метод на класа, тя трябва да е външна за класа.Как можем да постигнем това? - friend.
Също така в повечето случаи тези оператори връщат референция към поток, за да можем да навържем няколко такива операции заедно.


**Пример:**
```c++
class Distance {
private:
    int meters;           
    int cm;             
public:
    Distance() : meters(0), cm(0) {}

    Distance(int cm, int meters) {
        this->meters = meters;
        this->cm = cm;
    }

    friend std::ostream &operator<<( std::ostream &output, const Distance &d ) { 
        output << d.meters << "m" << d.cm << "cm." << std::endl;
        return output;            
    }

    friend std::istream &operator>>( std::istream  &input, Distance &d ) { 
        input >> d.meters >> d.cm;
        return input;            
    }
};
```