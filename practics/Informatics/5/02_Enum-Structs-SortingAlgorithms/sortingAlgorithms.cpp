#include <iostream>

void swap(int& a, int& b) {

    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], size_t size) {

    int minVal, minInd;

    for (size_t i = 0; i < size - 1; i++) {

        minInd = i;
        minVal = arr[minInd];

        for (size_t j = i + 1; j < size; j++) {

            if (arr[j] < minVal) {

                minInd = j;
                minVal = arr[j];
            }
        }

        if (minInd != i) {
            swap(arr[i], arr[minInd]);
        }
    }
}

void bubbleSort(int arr[], size_t size) {

    bool isSwap;

    for (size_t i = 0; i < size - 1; ++i) {

        isSwap = false;
        for (size_t j = 0; j < size - i - 1; ++j) {

            if (arr[j] > arr[j + 1]) { 

                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap) {
            break;
        }
    }
}

void printArray(const int arr[], size_t size) {

    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << ' ';

    std::cout << std::endl;
}

int main() {

    const size_t SIZE = 8;

    int arr[SIZE] = { 31, 2, 3, 4, 5, 6, 12, 11 };
    selectionSort(arr, SIZE);
    printArray(arr, SIZE);

    int brr[SIZE] = { 45, 10, 23, 4, 9, 1, 70, 12 };
    bubbleSort(brr, SIZE);
    printArray(brr, SIZE);

    return 0;
}
