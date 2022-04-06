#include "dynamic_arr.h"

void DynamicArray::copy(const DynamicArray& other) {
    this->capacity = other.capacity;
    this->size = other.size;

    this->data = new int[this->capacity];   // deep copy

    for (int i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

void DynamicArray::erase() {
    delete[] this->data;
}

void DynamicArray::resize() {
    if (this->size >= this->capacity) {
        this->capacity *= 2;
    }  

    // store data in bigger buffer
    int* bigger = new int[this->capacity];

    // copy all data from previous buffer
    for (int i = 0; i < this->size; i++) {
        bigger[i] = this->data[i];
    }

    // free alocated memory of this->data and set pointer to bigger
    this->erase();
    this->data = bigger;
}

DynamicArray::DynamicArray() {
    this->size = 0;
    this->capacity = 8;
    this->data = new int[this->capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    this->copy(other);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        this->erase();
        this->copy(other);
    }

    return *this;
}

DynamicArray::~DynamicArray() {
    this->erase();
}

int DynamicArray::getSize() const {
    return this->size;
}

int DynamicArray::getAtIndex(const int index) const {
    if (index < size) {
        return this->data[index];
    }

    return 0;
}

void DynamicArray::push_back(const int& element) {
    // first check is not needed if we have it in resize()
    if (this->size >= capacity || this->data == nullptr) {
        this->resize();    
    }
    
    this->data[this->size] = element;
    this->size++;
}

void DynamicArray::print() const {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}
