# **Задача 1**
Напишете програма,която описва две геометрични фигури:
- правоъгълник (широчина , дължина)
- кръг(радиус)

всяка от фигурите да поддържа метод enterData() в който да се въвеждат данните специфични за всяка от фигурите, както и метод showArea() който извежда лицето на фигурата с подходящо съобщение.

# **Задача 2**
Да се дефинира абстрактен клас Device, който поддържа следните данни:
 * Модел – символен низ
 *  Марка – символен низ
 *  Цена – цяло число

Да се дефинират методи за принтиране на информацията на едно устройство, писане и
четене във файл.  

Нека класът Phone наследи Device като го надгражда със следните характеристики:
 *  Брой камери - цяло число
 *  SecurityLockType – избор между лицево разпознаване и пръстов отпечатък  
 
Нека класът Laptop също наследи Device като за него има следната информация:
 *  Операционна система – MacOS, Linux, Windows
 *  Дали е с USB портове или с Thunderbolt
 *  Брой портове-цяло число

Нека Phone и Laptop имат свои имплементации на методите за принтиране на
информацията, писането и четенето от файл.     
Да се реализира клас TechnoShop, който представлява магазин за техника. Нека той
има име и съдържа списък от устройства. Да се напишат методи за добавяне и
премахване на устройство, премахването да става по подадени модел и марка,
записване на информацията на всички устройства във файл и четене на информация за
магазин и неговите артикули от файл.  
Помислете какво още ще ви е нужно, за да реализирате класа TechnoShop.
