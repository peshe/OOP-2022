# Седмица 11 - Виртуални методи и полиморфизъм. Абстрактни класове.

Виртуални функции:
=

Виртуалните функции са методи на базов клас и тези функции трябва да бъдат предефинирани(overridde) в класовете наследници(derive class).
Виртуалните функции гарантират, че е извикана правилната функция.

Виртуалните функции се декларират с ключовата дума virtual

Пример:
```
class base {
public:
    virtual void print()
    {
        cout << "print base class\n";
    }
};
 
class derived : public base {
public:
    void print()
    {
        cout << "print derived class\n";
    }
};
```

Чисто виртуални функции(pure virtual function):
=
Чисто виртуални функции са функции, които нямат имплементация. Имплементацията ще бъде написана от класа наследяващ базовия клас.

Пример:
```
class Base
{   
    // Data members of class
public:
    // Pure Virtual Function
    virtual void show() = 0;
    
   /* Other members */
};
```

Полиморфизъм:
=
Използваме го, когато един обект има различни поведения при различни ситуации.
Съществуват два типа полиморфизъм:
- compile time
	- предефиниране на функции
		Пример:
    ```
		class base {
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
		 
		class derived : public base {
		public:
			void print()
			{
				cout << "print derived class\n";
			}
		 
			void show()
			{
				cout << "show derived class\n";
			}
		};
    ```
	
	- предефиниране на оператори:
		Пример:
    ```
		class base {
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
		 
		class derived : public base {
		public:
			void print()
			{
				cout << "print derived class\n";
			}
		 
			void show()
			{
				cout << "show derived class\n";
			}
		};
    ```

- run time - възможно е чрез предефиниране на функции. По-точно когато наследник на базов клас предефинира негова виртуална функция

Пример:
```
class base {
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
 
class derived : public base {
public:
    void print()
    {
        cout << "print derived class\n";
    }
 
    void show()
    {
        cout << "show derived class\n";
    }
};
```
```
Изход:
print derived class
show base class
```

Абстрактни класове:
=
Абстракция - показване на нужната информация и скриване на детайлите.
Абстрактен клас е клас, който съдържа поне една pure virtual функция.

Пример:
```
class Base
{
	int x;
	public:
	virtual void show() = 0;
	int getX() { return x; }
};

int main(void)
{
	Base t;
	return 0;
}
```

Този пример ще доведе до compile error, защото не могат да бъдат създавани обекти от абстрактен клас.

Можем да създаваме референции от абстрактни класове, които да сочат към обекти от класове насладници на абстракния клас, които са имплементирали всички виртуални методи.
Ако класът наследник на абстрактия клас не предефинира виртуалните функции той също става абстарктен клас.
