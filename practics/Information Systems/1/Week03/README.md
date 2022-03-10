# Седмица 3 - Двоични файлове. Работа при пряк достъп.

Разлики между текстови и бинарни файлове:
=
Текстовите файлове съдържа текстова информация, докато бинарните са колекция от битове в нечетим от човек формат.

Текстовият поток съдържа ASCII символи. 
Двоичният поток може да се използва с всякакъв тип данни и предаването на информацията е едно към едно между потока и файла.

Отваряне на файл в двоичен режим:
=
```
// добавяне на библиотека за работа с потоци
#include <fstream>
```

```
//1ви вариант:
std::fstream binaryFile;
binaryFile.open("test.bin", std::ios::binary);
```

```
//2ри начин:
std::fstream binaryFile("test.bin", std::ios::binary);
```

Запис в бинарен файл на примитивни типове:
=
За запис в бинарен файл се използва метода **write**. 
Той приема като първи параметър елемента, който искаме да запишем представен като const char * и брой битове(размерността на елемента, който записваме)

```
//Пример:
std::ofstream binaryFile("test.bin", std::ios::binary);
int number = 12;
if(binaryFile.is_open()) {
 binaryFile.write((const char*)&number, sizeof(int));
 binaryFile.close();
}
...
```

Четене от бинарен файл на примитивни типове:
=
За четене от бинарен файл се използва метода **read**.
Той приема като първи параметър променлива, на която искаме да сложим стойност от файла и като втори параметър брой битове(размерността на елемента, който четем)

```
//Пример:
std::ifstream binaryFile("test.bin", std::ios::binary);
int number = 0;
if(binaryFile.is_open()) {
 binaryFile.read((char*)&number, sizeof(int));
 binaryFile.close();
}
...
```

Запис в бинарен файл на string:
=

```
//Пример със запис на string:
std::ofstream binaryFile(fileName, std::ios::binary);
std::string myString = "test";
if (binaryFile.is_open()) {
    unsigned size = myString.size();
    binaryFile.write((const char*)&size, sizeof(unsigned));
    binaryFile.write(myString.c_str(), size);
    binaryFile.close();
}
...
```

Четене от бинарен файл на string:
=

```
//Пример:
std::ifstream binaryFile("test.bin", std::ios::binary);
std::string stringFromFile;
if (binaryFile.is_open()) {
    unsigned sizeOfString = 0;
    binaryFile.read((char*)&sizeOfString, sizeof(unsigned));
    char* buffer = new char[sizeOfString + 1];
    binaryFile.read(buffer, sizeOfString);
    stringFromFile.append(buffer, sizeOfString);
    delete[] buffer;
    binaryFile.close();
}
...
```

Stream position:
=
- tellg()/tellp() – взима текущата позиция
- seekg(колко позиции, от къде)/seekp(колко позиции, от къде) – отмества указателя във файла спрямо определена посока (може да не се задава от къде)
- offset:
    ios::beg – отмества от началото на потока
    ios::cur – отмества от текущата позиция
    ios::end – отмества от края на потока
