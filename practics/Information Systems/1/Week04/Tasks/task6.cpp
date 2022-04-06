#include<iostream>


int convertNumber(char number[])
{
    int result = 0;
    for(int i =0 ; number[i] != '\0' ; ++i)
    {
        result *= 10;
        result += number[i] - '0';
    }
    return result;
}

class Arithmetics
{
    private:

    unsigned sizeOfValues{};
    int values[30];

    unsigned sizeOfOperations{};
    char operations[16];

    int result{};

    public:

    void processExpression(const char* expression)
    {
        if(expression == nullptr)
        {
            std::cout<<"invalid expression"<<std::endl;
            return;
        }
        char number[10];
        int convertedNumber;
        int currentNumIndex = 0 , valuesArrayIndex = 0 , operationsIndex = 0;

        for(int i = 0 ; expression[i] != '\0' ; ++i)
        {
            if(!(expression[i] >= '0' && expression[i] <= '9'))
            {
                number[currentNumIndex] = '\0';
                convertedNumber = convertNumber(number);
                values[valuesArrayIndex] = convertedNumber;
                sizeOfValues++;
                currentNumIndex =0;
                valuesArrayIndex ++;
                operations[operationsIndex] = expression[i];
                sizeOfOperations++;
                operationsIndex++;

            }
            else
            {
                number[currentNumIndex] = expression[i];
                currentNumIndex++;
            }
        }

        number[currentNumIndex] = '\0';
        convertedNumber = convertNumber(number);
        values[valuesArrayIndex] = convertedNumber;
        sizeOfValues++;
        
    }

    bool correctExpression()
    {
        return sizeOfValues > sizeOfOperations;
    }
    
    void claculateResult()
    {
        if(correctExpression())
        {
            result = values[0];
            for(int i = 1 , j = 0 ; i < sizeOfValues ; ++i , ++j)
            {
                switch (operations[j])
                {
                    case '+':
                        result += values[i];
                    break;

                    case '-':
                        result -= values[i];
                    break;

                    case '*':
                        result *= values[i];
                    break;

                    case '/':
                        result /= values[i];
                    break;
                
                    default:
                    break;
                }
            }
        }

    }

    int getResult()
    {
        return result;
    }


};


int main()
{

    Arithmetics calc;
    calc.processExpression("11+2");
    calc.claculateResult();
    std::cout<<calc.getResult()<<std::endl;
    return 0;
};