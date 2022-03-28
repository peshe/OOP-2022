#include<iostream>
#include<fstream>


void separateNumbers(const char* fileName)
{
    std::ifstream in(fileName);
    std::ofstream outputEven("evenNumbers.txt");
    std::ofstream outputOdd("oddNumbers.txt");
    if(!in.is_open() || !outputEven.is_open() || !outputOdd.is_open())
    {
        std::cout<<"Can't open file"<<std::endl;
        return;
    }
    int currentNumber;
    while(in>>currentNumber)
    {
        if(currentNumber %2 == 0)
        {
            outputEven<<currentNumber<<" ";
        }
        else
        {
            outputOdd<<currentNumber<<" ";
        }
    }
    in.close();
    outputEven.close();
    outputOdd.close();

}

int main()
{
    
    return 0;

}