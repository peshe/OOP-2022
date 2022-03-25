# Седмица 5 - Класове и обекти - жизнен цикъл. Конструктори и деструктори. Инициализация. Изключения.

Конструктори:
=

**Конструктор : - Constructor**
Конструкторът на клас е специален метод на класа, който се изпълнява всеки път, когато създаваме нови обекти от този клас.
Конструкторът може да приема или да не приема параметри.
Има същото име като класа и не връща никакъв тип, дори и void. Конструкторите могат да бъдат много полезни за задаване на начални стойности за определени член-данни.

```
class class_name
{
    class_name() // constructor with no parameters
    {
         // constructor Definition 
    }

    class_name(parameter1 , parameter2) // constructor with parameters
    {
         // constructor Definition 
    }
};
```

```
class Rectangle
{
    private:
    double width;
    double height;

    public:
    Rectangle() // конструктор без параметри
    {
        this->width = 1;
        this->height = 1;
    }

    Rectangle(const double& width_a , const double& heiht_a) // конструктор с параметри
    {
        this->width = width_a > 0 ? width_a : 1;
        this->height = heiht_a > 0 ? heiht_a : 1;
    }
};

int main()
{
    //създаване на обект от тип Rectangle с дефолтни стойности
    Rectangle firstRectangle(); // width = 0 , heigth = 0

    //създаване на обект от тип Rectangle със стойности подадени на конструктора
    Rectangle secondRectangle(5 , 9); // width = 5 , heigth = 9
    
    
}
```

**Копиконструктор: - Copy Constructor**

Копиконструкторът е конструктор, който създава обект, като го инициализира с обект от същия клас, който е бил създаден преди това. 
Копиращият конструктор се използва за :
    - инициализиране на един обект от друг (от същия тип).
    - копиране на обект, за да може да бъде подаден като аргумент на функция.
    - копиране на обект, за да може да бъде върнат от функция.
Ако копиконструкторът не е дефиниран в клас, самият компилатор го "дефинира", но ако класът (има една или повече )член данна указател и има заделяне на
 динамична памет , то е задължително да имаме копиконструктор, за да избегнем споделянето на памет.

Използването на копиконструктура става единствено и само при инициализиране на обект от клас(не можем да извикаме експлицитно копиконструктор ако обект е вече инициализиран)

```
classname (const classname &obj) 
{
   // body of constructor
}
```

```
class Rectangle
{
    private:
    double width;
    double height;

    public:
    Rectangle() // конструктор по подразбиране без параметри
    {
        this->width = 1;
        this->height = 1;
    }

    Rectangle(const double& width_a , const double& heiht_a) // конструктор по подразбиране с параметри
    {
        this->width = width_a > 0 ? width_a : 1;
        this->height = heiht_a > 0 ? heiht_a : 1;
    }

    Rectangle(const Rectangle& other) // Copy Constructor
    {
        this->width = other.width;
        this->height = other.height;
    }
};

int main()
{
 
    //създаване на обект от тип Rectangle със стойности подадени на конструктора
    Rectangle firstRectangle(5 , 9); // width = 5 , heigth = 9

    //създаване на обект от тип Rectangle със подаване на обект от същия тип (Rectangle)
    Rectangle firstRectangle(firstRectangle); // width = 5 , heigth = 9
    
}
```


**Оператор=**
Метода оператор= представлява предефиниране на дефоултното състояние на =, което ни позволява на даден обект от класа да му зададем стойност същата като на друг обект от същия клас
Пример:
Ако искаме една променлива от целочислен тип да има същата стойност като друга извършваме следното:
int a = 5;
int b;
b = a; // b рприсвоява стойността на а (използва дефоултното състояние на =)

Ако искаме обект на клас да има същата стойност като друг обект от същия клас:
Rectangle r1(5, 9);
Rectangle r2(3, 4);
r2 = r1; // това действие може да се извърши само ако в класа Rectangle ме предефинирали оператор=

Как да предефинираме оператор=
```
ClassName& operator=(const ClassName& other)
    {
        if(this != &other) { // правем проверка дали обекта, който подаваме на метода не е същия, с който работим
	 // ако работим с динамична памет -> изтриваме член данните, които са в динамичната памет
	 // стойностите на член данните се присвояват стойност по стойност от подадения обект (other)
	}

	return *this; // оператор= представлява метод -> връща стойност 
	// стойността, която връща е нашия променен обект 
    }
```

```
Пример:
class Rectangle
{
    private:
    double width;
    double height;

    public:
    Rectangle() // конструктор без параметри
    {
        this->width = 1;
        this->height = 1;
    }

    Rectangle(const double& width_a , const double& heiht_a) // конструктор с параметри
    {
        this->width = width_a > 0 ? width_a : 1;
        this->height = heiht_a > 0 ? heiht_a : 1;
    }

    Rectangle& operator=(const Rectangle& other) // оператор=
    {
        if(this != &other) {
	 this->width = other.width;
         this->height = other.height;
	}

	return *this;
    }
};
```

Деструктори: - Destructors
=

Деструкторът е специален метод на класа, който се изпълнява винаги, когато обекта от неговия клас излезе извън обхват или когато се извика delete към указател сочещ обекта на този клас.
Деструкторът  има  същото име като класа с префикс : тилда (~) и не може нито да връща стойност, нито да приема никакви параметри.
Деструкторът може да бъде много полезен за освобождаване на ресурси, преди да излезе от програмата, като затваряне на файлове, изтриване на динамично заделена памет и т.н.

```
class Rectangle
{
    private:
    double width;
    double height;

    public:
    Rectangle() // конструктор без параметри
    {
        this->width = 1;
        this->height = 1;
    }

    Rectangle(const double& width_a , const double& heiht_a) // конструктор с параметри
    {
        this->width = width_a > 0 ? width_a : 1;
        this->height = heiht_a > 0 ? heiht_a : 1;
    }

    ~Rectangle() // деструктор
    {
        cout << "Object is being deleted" << endl;
    }
};
```
