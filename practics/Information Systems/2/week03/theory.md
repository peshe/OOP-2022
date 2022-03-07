**Файлове**

**Създаване на файлов поток и отваряне на файл**

- Използваме библиотеката fstream
- fstream myFileStream; - създаване на файлов поток
- myFileStream.open(&quot;myFile.txt&quot;); - отваряне на файл
- fstream myFileStream(&quot;myFile.txt&quot;) - създава файлов поток и отваря файл (комбинира горните две точки)
- ifstream fi(&quot;fileName&quot;) - отваря файла за четене т.е. ще четем от този файл
- ofstream fo(&quot;filename&quot;) - отваря файла за писане т.е. ще пишем в този файл

**Режим на отваряне**

При отваряне на файл, можем да изберем  **mode**  (режим) на работа, комбинирайки следните флагове:

| **Флаг** | **Значение** |
| --- | --- |
| **ios::in** | Отваряне с операции за вход |
| --- | --- |
| **ios::out** | Отваряне с операции за изход |
| **ios::binary** | Отваряне в двоичен режим |
| **ios::ate** | **Първоначално**  поставя позицията на указателя края на файла |
| **ios::app** | **Всички**  изходни операции се извършват на края на файла, добавяйки към досегашните данни |
| **ios::trunc** | При отваряне за изходни операции за съществуващ файл – досегашните данни се изтриват |

Важно

- ios::in флагът е винаги вдигнат при отваряне на поток за вход
- ios::out флагът е винаги вдигнат при отваряне на поток за изход

**Писане във файл:**

std::ofstream of\_stream;

of\_stream.open(&quot;filename.txt&quot;);

// check successful open

if (!of\_stream.is\_open())

{

// handle error

}

of\_stream \&lt;\&lt; &quot;I like files\n&quot;;

of\_stream \&lt;\&lt; &quot;a lot\n&quot;;

of\_stream \&lt;\&lt; 512;

of\_stream.close();

**Четене от файл:**

std::ifstream if\_stream;

if\_stream.open(&quot;filename.txt&quot;);

// check successful open

if (!if\_stream.is\_open())

{

// handle error

}

const int buffer\_size = 1024;

char line[buffer\_size];

while (if\_stream.getline(line, buffer\_size))

{

std::cout \&lt;\&lt; line \&lt;\&lt; &quot;\n&quot;;

}

if\_stream.close();

**Затваряне на файл**

- myFileStream.close() - затваря файл. След като е затворен можем да използваме същата променлива за да отворим друг файл myFileStream.open(&quot;textFile.txt&quot;, ios::out | ios::app)
- Въпреки това, че компилатора се сърди повече за липсваща ; отколкото за незатворен файлов поток е хубаво след като приключим работа с даден файл да го затворим