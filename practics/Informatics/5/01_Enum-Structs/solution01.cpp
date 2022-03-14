#include <iostream>

// Комплексно число представялващо две числа- real е реалната част, а imaginary е имагинерната част
struct ComplexNumber {

    double real;
    double imaginary;
};

/*
 * Функция, която чете от конзолата едно комплексно число. Подава се по псевдоним, в противен
 * случай ще се работи с локалното копие, а не с обекта, който сме подали като параметър на функцията.
*/
void readComplexNumber(ComplexNumber& compNum) {

    std::cout << "Enter complex number:";
    std::cin >> compNum.real >> compNum.imaginary;
}

/*
 * Отпечатва на конзолата комплексното число.
 * Типът на параметъра е константен, защото няма да променяме подадения обект.
 * Референцията е за да избегнем копиране на обекта.
*/
void printComplexNumber(const ComplexNumber& compNum) {

    std::cout << compNum.real;

    if (compNum.imaginary >= 0) {
        std::cout << '+' << compNum.imaginary << 'i';

    }  else {
        std::cout << '-' << -compNum.imaginary << 'i';
    }

    std::cout << std::endl;
}

// Функция, която събира две комплексни числа.
ComplexNumber sumOfComplexNumbers(const ComplexNumber& compNum1, const ComplexNumber& compNum2) {

    // Друг начин за инициализация на комплексното число result 
    // ComplexNumber result{ compNum1.real + compNum2.real , compNum1.imaginary + compNum2.imaginary };
    
    ComplexNumber result;
    result.real      = compNum1.real + compNum2.real;
    result.imaginary = compNum1.imaginary + compNum2.imaginary;
    return result;
}

int main() {

    ComplexNumber compNum1;
    readComplexNumber(compNum1);

    ComplexNumber compNum2;
    readComplexNumber(compNum2);

    printComplexNumber(sumOfComplexNumbers(compNum1, compNum2));


    ComplexNumber compNum3 = { 7, 1 };  
    ComplexNumber compNum4 = { 8, 2 };  

    ComplexNumber result = sumOfComplexNumbers(compNum3, compNum4);
    printComplexNumber(result);
    

    ComplexNumber compNum5; 
    compNum5.real = -3;
    compNum5.imaginary = -8;

    ComplexNumber compNum6;  
    compNum6.real = 10;
    compNum6.imaginary = 11;

    printComplexNumber(sumOfComplexNumbers(compNum5, compNum6));

    return 0;
}
