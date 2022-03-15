#include <iostream>
#include <fstream>
#include<string>

void saveResultsToFile(const char* fileName, int result)
{
    std::ofstream fileOut(fileName, std::ios::app);
    if (fileOut.is_open()) {
        fileOut << result << '\n';
        fileOut.close();
    }
    else {
        std::cout << "Unable to open" << std::endl;
    }

}

int expressionResult(const char* expression, unsigned size) {
    int firstNumber = 0;
    int secondNumber = 0;
    char operation = 'n';
    for (unsigned i = 0; i < size; i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9') {
            if (operation == 'n') {
                firstNumber = firstNumber * 10 + (expression[i] - 48);
                continue;
            }
            secondNumber = secondNumber * 10 + (expression[i] - 48);
        }
        else if (expression[i] == '+' ||
            expression[i] == '-' ||
            expression[i] == '*' ||
            expression[i] == '/') {
            operation = expression[i];
        }
        else {
            std::cout << "Invalid expression" << std::endl;
            return 0;
        }
    }

    switch (operation)
    {
        case '+': return firstNumber + secondNumber;
        case '-': return firstNumber - secondNumber;
        case '*': return firstNumber * secondNumber;
        case '/': return secondNumber != 0 ? firstNumber / secondNumber : 0;
    }
}

int main()
{
    char expression[256] = "13+2";

    int result = expressionResult(expression, 4);

    saveResultsToFile("results.txt", result);

    return 0;
}