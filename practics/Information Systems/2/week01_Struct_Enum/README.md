### Структури
Mасивитe ни позволяваха да съхраняваме елементи от един и същи тип в последователна наредба. Например масив от цели числа, символи и тн. В реалния живот се налага да работим с елементи от различни типове. Тогава се намесват структурите. Структурите са типове данни дефинирани от потребителя, които ни позволяват да групираме елементи от различни типове и да ги съхраняваме.

```c++
struct <name>
{
  <member definition>;  //  int arr[5];
  <member definition>;  //  int age;
  <member definition>;  //  double weight; 
        ...
  <member definition>;
  
}<one or more variables of <name> type>;

/*---------- Example ----------*/

struct Student
{
  char name[20];
  char faculty_number[5];
  unsigned int age;

};

```

### Дефиниране на променливи от тип структура
За структурата в паметта не се отделя памет. Паметта се отделя чак когато създадем обект от тип структура. Както при обикновените типове и тук дефинирането на променливи и константи от даден потребителски тип(структура) става чрез името на типа и името на променливата след това.

```c++
<name> <variable_name>;

/*---------- Example ----------*/

Student student_one;

```

### Достъп до елементите(членовете) на структурата
Достъпът до, който и да е, елемент на структурата се осъществява чрез оператора(.). Като използваме следния синтаксис:

```c++
<name>.<member_name>;

/*---------- Example ----------*/

cout << student_one.name << endl;
```

### Функции със структури
За структурите е характерно, че променливите от тип структура могат да се инициализират със стойности на вече дефинирана променлива от същия тип. 

```c++

Student student_one;
Student student_two = student_two;

```
Но за да работим със структурите ефективно трябва да дефинираме и други функции, като например функция:
* за инициализиране на елементите на структурата
* за извеждане на елементите на структурата на екрана
* за променяне стойностите на елементите на структурата

<br>

### Enums

Типът данни Enum е просто изброим числов тип, който може да съдържа стойност от предварително дефинирано множество. Стойностите са константи и опаковат някакво число с именувана константа. Например, ако моделираме някакъв обект, който искаме да има характеристика цвят, можем да използваме Enum:

```c++

еnum Color {
    RED
    GREEN,
    BLUE
}

struct Book {

    size_t pages;
    Color coverColor;
}

```

Конкретна спецификация на даден Енъм се достъпва по следния начин:

```c++

int main {

    Book myBook;
    myBook.coverColor = Color::Blue;
}

```