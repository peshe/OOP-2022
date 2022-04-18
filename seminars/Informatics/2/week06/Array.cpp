#include "./Array.h"
#include <cassert>
#include <cstddef>
#include <iostream>
#include <exception>

void Array::copy(const Array& other) {
    this->capacity = other.capacity;
    this->arr = new int[this->capacity];
    size = other.size;
    assert(size <= capacity);
    for (std::size_t i = 0; i < size; ++i) {
        this->arr[i] = other.arr[i];
    }
}
void Array::destroy() {
    delete[] this->arr;
}
Array::Array() {
    this->capacity = 8;
    arr = new int[this->capacity];
    size = 0;
}
Array::Array(const Array& other) {
    this->copy(other);
}
Array& Array::operator=(const Array& other) {
    if (this != &other) {
        this->destroy();
        this->copy(other);
    }
    return *this;
}
Array::~Array() {
    this->destroy();
}

int Array::getAtPosition(const std::size_t position) const {
    if (position < size) {
        return arr[position];
    } else {
        assert(false);
    }
}
void Array::setAtPosition(const std::size_t position, const int value) {
    if (position < size) {
        arr[position] = value;
    } else {
        assert(false);
    }
}
Array& Array::pushBack(int newValue) {
    if(size + 1 > capacity) {
        this->resize();
    } 
    arr[size] = newValue;
    size++;
    return *this;
}
void Array::resize() {
    int* newArr = new int[2*capacity];
    for(std::size_t i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    capacity *= 2;
    delete[] arr;
    arr = newArr;
}
std::size_t Array::getSize() const {
    return this->size;
}

void Array::print() const{
    for(int i = 0; i < this->size; ++i)
    {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

