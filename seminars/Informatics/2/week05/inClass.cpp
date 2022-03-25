#include <iostream>
#include <cassert>
class Array {
    int* arr;
    std::size_t size;
    std::size_t capacity;
public:
    Array() {
        this->capacity = 8;
        arr = new int[this->capacity];
        size = 0;
    }
    Array(const Array& other) {
        this->capacity = other.capacity;
        this->arr = new int[this->capacity];
        size = other.size;
        assert(size <= capacity);
        for (std::size_t i = 0; i < size; ++i) {
            this->arr[i] = other.arr[i];
        }
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] this->arr;
            this->capacity = other.capacity;
            this->arr = new int[this->capacity];
            size = other.size;
            
            assert(size <= capacity);

            for (std::size_t i = 0; i < size; ++i) {
                this->arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    int getAtPosition(const std::size_t position) const {
        if (position < size) {
            return arr[position];
        } else {
            assert(false);
        }
    }
    void setAtPosition(const std::size_t position, const int value) {
        if (position < size) {
            arr[position] = value;
        }
    }
    ... pushBack(int newValue) {

    }
    std::size_t getSize() const {
        return this->size;
    }

    ~Array() {
        delete[] arr;
    }
};
int main() {
    std::size_t n = 3;
    Array traicho, marijka;
    
    traicho.setAtPosition(0, 10);
    
    traicho.setAtPosition(1, 20);
    traicho.setAtPosition(2, 30);
    
    Array pencho;
    // pencho = traicho;
    
    for (std::size_t i = 0; i < pencho.getSize(); i++) {
        std::cout << pencho.getAtPosition(i) << " ";
    }
    std::cout << '\n';
    traicho.setAtPosition(2, 300);
    std::cout << pencho.getAtPosition(2) << " ";

    pencho = marijka;
    
}











