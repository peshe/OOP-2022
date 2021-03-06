## Задача 1

Реализирайте клас Company, който в себе си по същество е съвкупност от служители. Ще разглеждаме два вида служители - Developer и
Manager. За първият вид искаме да имаме информация за:

• име; </br>
• стаж (в месеци); </br>
• дали знае C++;</br>
• дали знае C#; </br>

А за Manager:

• име; </br>
• стаж (в месеци); </br>
• колко човека управлява </br>

Изполвайте механизма на наследяване при реализацията на Manager и Developer. Предимството, което може да използваме тук, е в Company да имаме член данна Employee** (където Employee е базовия клас), тоест динамично заделен масив от указатели към Employee, или Employee* за статичен масив, където тези указатели сочат специализираните обекти, т. е. Manager и Developer. Това е възможно, защото

```c++
Employee* emp = new Developer("Mark", 12)
```

Е не само валиден синтаксис в езика, но и много мощно средство изобщо.

Помислете кои ще бъдат общите данни в базовия клас, и какво ще добавят наследниците.

Програмата да може да извършва следните операции:
• постъпване на нов служител;

```c++
void addEmployee(const Employee *emp)
```

• напускане на служител;

Помислете дали виждате някакъв проблем с цялостния дизайн на програмата и по-специално със memory management-а и object ownership-а.

## Бонус

Вече сте видяли в Haskell и функцинолното програмиране как композирането на функции (Функции от по висок ред) може да бъде много мощен и елегантен начин за решаването на различни проблеми. В c++ можем да постигнем същото нещо, макар и по малко по-странно изглеждащ начин.

добавете към Company метод 
```c++
void sort(bool(*comparator)(const Employee*, const Employee*));
```

който приема указател към функция, сравняваща два работника с return type bool. Така ще имаме възможността един път да сортираме например лексикографски, по име на работник, или пък по месеци стаж (Това зависи от comparator). Сортиращият алгоритъм е по ваш избор.