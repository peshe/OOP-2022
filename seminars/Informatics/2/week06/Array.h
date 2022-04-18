#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

class Array {
    int* arr;
    std::size_t size;
    std::size_t capacity;
    void copy(const Array& other);
    void destroy();
    void resize();
public:
    Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    int getAtPosition(const std::size_t position) const;
    void setAtPosition(const std::size_t position, const int value);
    Array& pushBack(int newValue);
    std::size_t getSize() const;
    void print() const;
};

#endif // ARRAY_H
