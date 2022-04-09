#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    int size;
public:
    String() {}

    String(const char* str) {
        std::cout << "Created" << std::endl;
        this->size = strlen(str);
        this->data = new char[this->size];
        memcpy(this->data, str, this->size);
    } 

    String (const String& other) {
        std::cout << "Copied" << std::endl;
        this->size = other.size;
        this->data = new char[this->size];
        memcpy(this->data, other.data, this->size);
    }

    String(String&& other) noexcept {
        std::cout << "Moved" << std::endl;
        this->size = other.size;
        this->data = other.data;  // assigning the pointer!!!
    
        other.size = 0;
        other.data = nullptr; // making other "hollow"
    }

    ~String() {
        std::cout << "Destroyed" << std::endl;
        delete[] this->data;
    }

    void print() {
        for (int i = 0; i < this->size; i++) {
            std::cout << this->data[i];
        }

        std::cout << std::endl;
    }
};

class Entity {
private:
    String name;
public:
    Entity(const String& _name) : name(_name) {}
    
    Entity(String&& _name) : name((String&&)_name) {}

    void printName() {
        this->name.print();
    }
};

int main() {
    Entity e("nasko");
    e.printName();
}