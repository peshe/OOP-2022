Вие работите в голяма компания за разработване на игри. От днес сте в нов екип и ви е поставена следната задача:

Създайте клас Hero, описващ герой в новата игра. Всеки Hero има име и "живот". 
За героя трябва да може да се получава информация за това, колко "живот" има. 
Също така героят трябва да може да се представя. 
Hero трябва да има чист виртуален метод void attack(Hero* enemy).

Създайте клас Magician, описващ магьосник, наследяващ класа Hero. 
Магьосникът има име, "живот" и "мана". За магьосника трябва да може да се получава информация за това, 
колко "живот" има, 
и за това, колко "мана" има. 
Магьосникът също трябва да може да се представя. 
Методът attack на магьосника отнема точно толкова живот от противника, 
колкото "мана" има в момента магьосникът. 
Освен това всяка атака намалява текущата "мана" на магьосника с 20. 
По подразбиране магьосникът се инициализира със 100 "живот" и 200 "мана".

Създайте клас Warrior, описващ воин, наследяващ класа Hero. 
Воинът има име, "живот" и "ярост". За воина трябва да може да се получава информация за това, колко "живот" има, 
и за това, колко "ярост" има. Воинът също трябва да може да се представя. 
Методът attack на воина отнема на противника толкова "живот", колкото е текущата "ярост" на воина плюс 10. 
Всяка атака увеличава текущата "ярост" на воина с 20. 
По подразбиране воинът се инициализира с 0 "ярост" и 120 "живот".

Създайте клас Arena, описващ арена за битка между герои.
Арената получава брой герои и списък от такива при създаването си. 
Напишете метод, който извежда данни за героите в битката на всеки рунд. Един рунд представлява
сбор от по една атака на всеки герой към всеки герой.

Да се направи демонстрация на класовете.