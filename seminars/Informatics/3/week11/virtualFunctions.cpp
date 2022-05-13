#include <iostream>
  
class Animal {
public:
    virtual void speak() {
        std::cout<< "..."<< std::endl;
    }
};

class Dog: public Animal {
public:
    void speak() {
        std::cout<< "woof woof"<< std::endl;
    }
};

class Fox: public Animal {
public:
    void speak() {
        std::cout<< "wa pa pa pa pa pa pow"<< std::endl;
    }
};

void animalSpeak(Animal& animal) {
    animal.speak();
}
  
int main()
{
    Dog d;
    Fox f;
    animalSpeak(f);
}