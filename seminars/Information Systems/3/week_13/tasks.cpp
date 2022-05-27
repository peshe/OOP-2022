#include <iostream>

template <typename T>
void swap(T& first, T& second) {
    T temp;
    temp = first;
    first = second;
    second = temp;
}

// [0,4,5,31,2,-3,5,7]
template <typename T>
unsigned int maxElementIndex(T* arr, int size) {
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[maxIndex] < arr[i]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}

template <typename T>
T& maxElement(T* arr, int size) {
    T max = arr[0];

    for (int i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

template <typename T>
unsigned int minElementIndex(T* arr, int size) {
    int minindex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minindex]) {
            minindex = i;
        }
    }

    return minindex;
}

// [1,2,3,3,5]
template <typename T>
bool ordered(T* arr, int size) {
    for (int i = 0, j = i + 1; j < size; i++, j++) {
        if (arr[i] > arr[j]) 
            return false;
    }

    return true;
}

template <typename T>
bool member(T* arr, int size, T x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x)
            return true;
    }

    return false;
}

int main() {
    int size = 5;
    int* arr1 = new int[size];
    arr1[0] = 2;
    arr1[1] = 55;
    arr1[2] = 4;

    double* arr2 = new double[size];
    arr2[0] = 2.316;
    arr2[1] = 2.355;
    arr2[2] = 4.111;
}