# Файлове (част 2). Двоични файлове.

## Режими за работа с файлове


| Режим:| Ефект:                                                                      | 
|--------|------------------------------------------------------------------------------|
|ios::in |Отваря файл за четене  (по подразбиране на ifstream)                           |
|ios::out    |Отваря файл за четене (по подразбиране на ofstream)                        |
|ios::binary | Отваря файл в двоичен режим                                               |
|ios::trunc  | Ако файлът съществува,  съдържанието му се изтрива след отваряне на поток |
|ios::app    | Отваря файлът за вмъкване. Поставя put указателят в края. Не се допуска вмъкване преди края на потока      |
|ios::ate    | Отваря файлът за вмъкване. Поставя put указателят в края. Допуска вмъкване на прозиволни места                |
|ios::nocreate | Отваря за вмъкване, само ако файлът с указаното име съществува.|
ios::noreplace | Отваря за вмъкване само ако файлът с указаното име не съществува.|
### Пример:
 ```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream f("test.txt", std::ios::out | std::ios::app);

	if (!f.is_open())
	{
		std::cout << "Error while opening file!" << std::endl;
		return -1;
	}
	f << 33; //appends at the end of the file

	f.close();
	return 0;
}
 ```
## Флагове на състоянията на потока 
| Флаг:| Значение:                                                                      | 
|--------|------------------------------------------------------------------------------|
|bad()   | Има загуба на информация. Някоя операция за четене и писане не е изпълнена. |
|fail() |Последната входно/изходна операция е невалидна.|
| eof() | Достигнат е края на файла. |
|good() | Всички операции са изпълнени успешно.|
|clear()| Изчиства състоянието на потока (Вече good() ще върне истина).|

## Двоични файлове.

Изпоилзваме функциите:

1. .read(char* memoryBlock, size_t size);
2. .write(const char* memoryBlock, size_t size);

Обърнете внимание, че функцията приема **char***. Ако искаме да запазим променлива от друг вид, ще трябва експлицитно да преобразуваме указателя към тип char* (без значение, че указателят не сочи към елементи от тип char)

### Пример за писане в двоичен файл:
 ```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ofstream f("file.bin");

	int a = 123;

	f.write(reinterpret_cast<char*>(&a), sizeof(int));

    f.close();

	return 0;
}
 ```
 ### Пример за четене от двоичен файл:
 
  ```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream f("file.bin");

	int a;

	f.read(reinterpret_cast<char*>(&a), sizeof(int));

	cout << a << endl;
    
    f.close();

	return 0;
}
 ```

 ### Съдържанието на двоичния файл:
     7B 00 00 00
 
Байтовете се записват в **обратна посока**. Най-старшият байт е последен. Следователно запаментеното число е **0000007B**, което е точно шестанйсетичния запис на числото **123**.
 
  ### Примери за запазване на стуктури във файл.
- запазване на структура, която не използва динамична памет 
```c++
#include <iostream>
#include <fstream>

struct Test
{
    bool b;
    int x;
};

int main()
{

    { //write
        Test t = { true, 45 };
        std::ofstream file("test.dat", std::ios::binary);

        if (!file.is_open())
            return -1;

        file.write(reinterpret_cast<char*>(&t), sizeof(t));
    }

    { //read
        Test t;
        std::ifstream file("test.dat", std::ios::binary);

        if (!file.is_open())
            return -1;

        file.read(reinterpret_cast<char*>(&t), sizeof(t));
        std::cout << t.b << " " << t.x << std::endl;
    }

}
```
- запазване на структура, която използва динамична памет
```c++
#include <iostream>
#include <fstream>
#include <cstring>


struct Student
{
	char* name;
	int age;
	int fn;
};

void saveStudent(std::ofstream& file, const Student& st)
{
	size_t nameLen = strlen(st.name) + 1;
	file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
	file.write(st.name, nameLen);
	file.write(reinterpret_cast<const char*>(&st.age), sizeof(st.age));
	file.write(reinterpret_cast<const char*>(&st.fn), sizeof(st.fn));
}

void loadStudent(std::ifstream& file, Student& st)
{
	size_t nameLen;
	file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));

	st.name = new char[nameLen];
	file.read(st.name, nameLen);

	file.read(reinterpret_cast<char*>(&st.age), sizeof(st.age));
	file.read(reinterpret_cast<char*>(&st.fn), sizeof(st.fn));
}

int main()
{

	{ //writing students to binary file

		Student s1;
		s1.name = new char[5];
		strcpy(s1.name, "ivan");
		s1.fn = 9999;
		s1.age = 30;


		Student s2;
		s2.name = new char[6];
		strcpy(s2.name, "peter");
		s2.fn = 5555;
		s2.age = 50;

		std::ofstream file("Students.dat", std::ios::binary);
		
		if (!file.open())
		{
			std::cout << "Error while writing to binary file!" << std::endl;
			delete[] s1.name, s2.name;
			return -1;
		}
		
		saveStudent(file, s1);
		saveStudent(file, s2);

		delete[] s1.name, s2.name;
	}

	{ //reading students from binary file

		std::ifstream file("Students.dat", std::ios::binary);
		
		if (!file.open())
		{
			cout << "Error while reading from file!" << endl;
			return -1;
		}
		
		Student s1, s2;

		loadStudent(file, s1);
		loadStudent(file, s2);
		std::cout << s1.name << " " << s1.age << " " << s1.fn << std::endl;
		std::cout << s2.name << " " << s2.age << " " << s2.fn << std::endl;

		delete[] s1.name, s2.name;
	}
    return 0;
}
```