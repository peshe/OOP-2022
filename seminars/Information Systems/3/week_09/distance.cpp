#include <fstream>
#include <iostream>

class Distance {
private:
    int meters;           
    int cm;     

    // static int count;        
public:
    Distance() : meters(0), cm(0) {
    }

    Distance(int cm, int meters) {
        this->meters = meters;
        this->cm = cm;
    }

    friend std::ostream &operator<<(std::ostream &output, const Distance &d ) { 
        output << d.meters << "m" << d.cm << "cm." << std::endl;
        return output;            
    }

    friend std::istream &operator>>(std::istream  &input, Distance &d ) { 
        input >> d.meters >> d.cm;
        return input;            
    }
};

int main() {
   Distance D1(11, 10), D2(5, 11), D3;

   std::cout << "Enter the value of D3: " << std::endl;
   std::cin >> D3;
   std::cout << "First Distance: " << D1 << std::endl;
   std::cout << "Second Distance: " << D2 << std::endl; // TODO: upgrade this with static
   std::cout << "Third Distance: " << D3 << std::endl;

   std::cout << D1;
   return 0;
}