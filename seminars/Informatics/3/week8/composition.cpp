#include <iostream>
#include <string>

// probably useless on its' own
class CarPart {
    string name;
};

// useful, even if not part of garage
class Car {
	string name;
    CarPart engine;
    CarPart body;
}

class Garage {
	Car* spot1;
	Car* spot2;
}

int main() {
}