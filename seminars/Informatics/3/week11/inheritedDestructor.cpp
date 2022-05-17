#include <iostream>

class A {
protected:
    int itemCount;
public:
    A(int itemCount): itemCount(itemCount) {
        std::cout<< "creating A"<< std::endl;
    }
    ~A() {
        std::cout<< "deleting A"<< std::endl;
    }
};

class B: public A {
    int* items;
public:
    B(int itemsCount): A(itemsCount)  {
        std::cout<< "creating B"<< std::endl;
        items = new int[itemCount]; 
    }
    B(const B& other) = delete;
    const B& operator=(const B& other) = delete;
    ~B() { 
        std::cout<< "deleting B with "<< itemCount<< " items"<< std::endl;
        delete [] items; 
    }
};

int main() {
    B(5);
    
    return 0;
}