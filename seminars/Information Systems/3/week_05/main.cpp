#include <iostream>
#include <cstring>
#include "player.cpp"

class Person {
private:
  char* name;
  int age;
public:
  const char* getName() const;
  void setName(const char* other_name);
  bool operator==(const Person& other) {
      return this->age == other.age &&
             strcmp(this->name, other.getName()) == 0;
  }
  bool operator!=(const Person& other) {
      // *this -> Person 
      return !(*this == other);
  }
};

int main() {
    // Person p1;
    // Person p2;
    // // Person result = p1 + p2;
    // bool areEqual = p1 == p2;
    // bool areNotEqual = p1 != p2;
    // std::cout << areEqual;

    Player* p1 = new Player();
}