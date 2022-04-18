# Седмица 7 - Предефиниране на оператори

В C++ можем да предефинираме повечето от наличните вградените оператори. По този начин можем да използваме и оператори с дефинирани от нас типове.
Предефинираните оператори са функции със специални имена: ключовата дума "оператор", последвана от символа за дефинирания оператор. Както всяка друга функция, предефинирания оператор има тип, който връща и списък с параметри, които прием.

**class_name operator+(const class_name&);**

пример1 за предефиниран оператор + :
=
```
#include <iostream>
using namespace std;

class Box {
   public:
      ...
      
      // Overload + operator to add two Box objects.
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }
      
   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};

// Main function for the program
int main() {
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box
   
 
   ....

   // Add two object as follows:
   Box3 = Box1 + Box2;

   return 0;
}
```

В горния пример operator+ връща нов обект от тип Box чиято стойност се присвоява на Box3.

пример2 за предефиниран оператор ++ :
=

```
#include <iostream>
using namespace std;
 
class Time {
   private:
      int hours;             // 0 to 23
      int minutes;           // 0 to 59
      
   public:
       // constructors....
      
      // overloaded prefix ++ operator -> ++object
      Time operator++ () {
         ++minutes;          // increment this object
         if(minutes >= 60) {
            ++hours;
            minutes -= 60;
         }
         return Time(hours, minutes);
      }
      
      // overloaded postfix ++ operator -> object++
      Time operator++( int ) {
      
         // save the orignal value
         Time T(hours, minutes);
         
         // increment this object
         ++minutes;                    
         
         if(minutes >= 60) {
            ++hours;
            minutes -= 60;
         }
         
         // return old original value
         return T; 
      }
};

int main() {
   Time T1(11, 59), T2(10,40);
 
   ++T1;                    // increment T1
   T1.displayTime();        // display T1
   ++T1;                    // increment T1 again
   T1.displayTime();        // display T1
 
   T2++;                    // increment T2
   T2.displayTime();        // display T2
   T2++;                    // increment T2 again
   T2.displayTime();        // display T2
   return 0;
```

Streaming:
=
The stream operators:

**operator << output**

**operator >> input**

В C++ можем да въвеждаме и извеждаме вградените типове данни, използвайки операторите  >> и  <<.
Операторите за въвеждане и извеждане също могат да бъдат предефинирани, за да можем да ги използваме за създадените от нас типове.

Когато предефинираме тези оператори пишем функцията friend...ЗАЩО?

При тези оператори, първият параметър е поток. Тъй като нямате достъп до обекта на потока (не можем да го променяте), функцията не може да бъде метод на класа, тя трябва да е външна за класа.Как можем да постигнем това?
(припомнете си от теорията от week6) - friend functions
Също така в повечето случаи тези оператори връщат референция към поток, за да можем да навържем няколко такива операции заедно.

пример:
```
#include <iostream>
using namespace std;
 
class Distance {
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
      
   public:
      //constructors

    
      // operator<< връща обект от тип -> ostream & и приема като параметри -> обект от тип ostream и обект от тип Distance
      friend ostream &operator<<( ostream &output, const Distance &D ) { 
         output << "F : " << D.feet << " I : " << D.inches;
         return output;            
      }
       
      // operator>> връща обект от тип -> istream & и приема като параметри -> обект от тип istream и обект от тип Distance
      friend istream &operator>>( istream  &input, Distance &D ) { 
         input >> D.feet >> D.inches;
         return input;            
      }
};

int main() {
   Distance D1(11, 10), D2(5, 11), D3;

   cout << "Enter the value of object : " << endl;
   cin >> D3;
   cout << "First Distance : " << D1 << endl;
   cout << "Second Distance :" << D2 << endl;
   cout << "Third Distance :" << D3 << endl;

   return 0;
}
```

output:
```
Enter the value of object :
70
10
First Distance : F : 11 I : 10
Second Distance :F : 5 I : 11
Third Distance :F : 70 I : 10
```

Навързваме няколко операции заедно
```
int main() {
   Distance D1(11, 10), D2(5, 11), D3;

   cout << "Enter the value of object : " << endl;
   cin >> D3;
   cout << "First Distance : " << D1 << "Second Distance :" << D2 << "Third Distance :" << D3 << endl;

   return 0;
}
```
