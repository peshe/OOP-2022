##  Потоци и Файлове (част 1). Текстови файлове.
Видове потоци:
 - Потоци за вход (istream).
 - Потоци за изход (ostream).
 
![enter image description here](https://i.ibb.co/VDdDSnM/potoci.gif)


#####  Пример за работа с поток за вход (cin)
 ```c++
#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;
}
 ```
 Четем от стандартния вход.

#####  Пример за работа с поток за изход (cout)
 ```c++
#include <iostream>

int main()
{
	int a = 10;
	int b = 12;
	int c = a + b;

	std::cout << a << " + " << b << " = " << c << std::endl;
}
 ```
	
### Работа с поток за вход от файл (ifstream)
Пример за четене от файл!
 ```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file("myFile.txt");

	if (!file.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}
	int a, b;

	file >> a >> b;

	file.close();
}
```
Пример за прочитане на цялото съдържание файл:
 ```c++
#include <iostream>
#include <fstream>

const int BUFF_SIZE = 1024;
int main()
{
	std::ifstream file("myFile.txt");

	if (!file.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}

	while (!file.eof())
	{
		char buff[BUFF_SIZE];
		file.getline(buff, BUFF_SIZE);
		
		//do something with the line
		std::cout << buff << std::endl;
	}
	file.close();
}
```
### Работа с поток за изход към файл (ofstream)
   
 ```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ofstream file("myFile.txt");

	if (!file.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}
	int a = 3;
	int b = 10;

	file << a << " " << b << " " << a + b << std::endl;
	
	if(!file.eof()) //check if the file has ended
		std::cout << "The file contains more data after the two integers!" << std::endl;

	file.close();
}
 ```

 - ifstream или istream - get указател, който реферира елемента, който ще се прочете при следващата входна операция. 

 - ofstream или ostream - put указател, който реферира мястото, където ще се запише следващият елемент.

### Режими на работа

 ```c++
	std::ifstream str("file.txt", <режим на работа>).
 ```
Режимът на работа е цяло число. 

| ios         | Ефект:                                                                                                                           |    |
|-------------|----------------------------------------------------------------------------------------------------------------------------------|----|
| ios::in     | Отваря файл за извличане.                                                                                                        | 1  |
| ios::out    | Отваряне на файл за вмъкване. Допуска се вмъкване на произволни места във файла. Ако файлът съществува, съдържанието се изтрива. | 2  |
| ios::ate    | Отваря за вмъкване и установява указателя put в края на файла. Допуска вмъкване на произволни места.                             | 4  |
| ios::app    | Отваря за вмъкване и установява указателя put в края на файла                                                                    | 8  |
| ios::trunc  | Ако файлът съществува, съдържанието се изтрива.                                                                                  | 16 |
| ios::binary | Превключва режима от текстов в двоичен                                                                                           | 32 |
 

 ```c++
	std::ostream file("file.txt", std::ios::out | std::ios::app).
 ```