# Седмица 2 - Файлове - основни концепции. Текстови файлове. Преглед на fstream

C++ ни предоставя следните класове за работа с файлове:

**ofstream**:  за писане във файл

**ifstream**:  за четене от файл

**fstream**:  за четене и писане от/във файл

Как да създадем файл:
=
```
Iн. ofstream fileOut(“NameOfFile”);
```

```
IIн. ofstream fileOut;

fileOut.open(“NameOfFile”);
```

Отваряне на файл:
=
За да отворим файл със stream обект използваме неговия метод open();

```
open (filename, mode);

filename - името на файла
mode - режим на отваряне на файла (не е задължителен)
```

```
Пример:

ofstream myfile;
myfile.open("example.bin", ios::out | ios::app | ios::binary);

ofstream myfile;
myfile.open ("example.bin");
```

Проверка дали файла е отворен:
=

```
if(fileOut.is_open())

{

	//действие
  
}

else

{

	std::cout << “Unable to open\n”;
  
}
```

Затваряне на файл:
=
Когато приключим с четенето/въвеждането на информация във файл ВИНАГИ трябва да го затворим.

```
myFile.close();
```

Състояния на файла(флагове): 
=

  **in** -         Opens the file to read(default for ifstream)

  **out** -        Opens the file to write(default for ofstream)

  **binary** -     Opens the file in binary mode

  **app** -        Opens the file and appends all the outputs at the end

  **ate** -         Opens the file and moves the control to the end of the file

  **trunc** -      Removes the data in the existing file

  **nocreate** -   Opens the file only if it already exists

  **noreplace** -  Opens the file only if it does not already exist

Режимите могат да бъдат въведени като втори параметър на конструктура на file stream обекта или да бъдат записани в метода open().

```
Пример:

    std::ofstream os("foo.txt", std::ios::out | std::ios::trunc);

    std::ifstream is;
    is.open("foo.txt", std::ios::in | std::ios::binary);
```

Дефолтни режими:
=
ifstream - ios::in
ofstream -  ios::out
fstream - ios::in | ios::out

Прочитане на файл:
=
Четене на файл с оператор **>>**:
  Оператор **>>** прочита текст от файл докато не достигне white space character (" "-(space) или край на реда-'\n')

```
if ( myfile.is_open() ) 
{    
    while ( !myfile.eof() ) 
    {
        myfile >> myString;
        std::cout<<myString<<std::endl;
    }
}
```

Четене на файл с **get()**:
  Освен чрез оператор >> можем да четем файл с метода get() , която прочита по един символ get() не пропуска white space characters

```
if ( myfile.is_open() ) 
{
    char mychar;
    while ( !myfile.eof() ) 
    {
        mychar = myfile.get();
        std::cout << mychar;
    }
}
```

Четене на файл с **getline()**:
  Друг начин за прочитане на файл е с метода getline() , който прочита цял ред от файла (до достигане на '\n')

```
std::string myline;
if ( myfile.is_open() ) 
{
    while (!myfile.eof() ) 
    {
        std::getline (myfile, myline);
        std::cout << myline << '\n';
    }
}
```

Въвеждане на текст във файл:
=
За въвеждане на текст във файл използваме оператор **<<**

```
  ofstream myfile ("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
```
