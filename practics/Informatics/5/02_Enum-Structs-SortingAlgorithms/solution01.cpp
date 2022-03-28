#include<iostream>

const size_t SIZE = 4;

using std::cin;
using std::cout;
using std::endl;

struct RationalNumber {

    int numerator;
    int denominator;
};

void readRationalNumber(RationalNumber& ratNum) {

    cout << "Enter rational number:";
    cin >> ratNum.numerator >> ratNum.denominator;
}

void printRationalNumber(const RationalNumber& ratNum) {

    cout << ratNum.numerator << " / " << ratNum.denominator << endl;
}

RationalNumber sumRatNums(const RationalNumber& rat1, const RationalNumber& rat2) {

    RationalNumber result;
    result.numerator   = rat1.numerator * rat2.denominator + rat2.numerator * rat1.denominator;
    result.denominator = rat1.denominator * rat2.denominator;
    return result;
}

RationalNumber multRatNums(const RationalNumber& rat1, const RationalNumber& rat2) {

    RationalNumber result;
    result.numerator   = rat1.numerator * rat2.numerator;
    result.denominator = rat1.denominator * rat2.denominator;
    return result;
}

bool isGreaterThan(const RationalNumber& rat1, const RationalNumber& rat2) {

    return (rat1.numerator * rat2.denominator > rat1.denominator * rat2.numerator);
}

RationalNumber largestRatNum(const RationalNumber ratNums[]) {

    RationalNumber largest = ratNums[0];

    for (size_t i = 1; i < SIZE; ++i) {
        if (isGreaterThan(ratNums[i], largest)) {
            largest = ratNums[i];
        }
    }

    return largest;
}

void sortRatNums(RationalNumber ratNums[]) {

    for (size_t i = 0; i < SIZE - 1; ++i) {

        size_t index = i;
        RationalNumber tempMax = ratNums[i];

        for (size_t j = 0; j < SIZE; ++j) {

            if (isGreaterThan(ratNums[j], tempMax)) {
                index = j;
                tempMax = ratNums[j];
            }
        }
        
        if (index != i) {
            ratNums[index] = ratNums[i];
            ratNums[i] = tempMax;
        }
    }
}

int main() {

    return 0;
}
