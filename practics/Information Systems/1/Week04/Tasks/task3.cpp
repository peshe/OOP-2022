#include<iostream>

class NumbersSummator
{
    private:
    double cSum;
    unsigned changes;

    public:
    NumbersSummator(const double& startSum)
    {
        this->cSum = startSum;
        this->changes = 0;
    }

    double sum()
    {
        return this->cSum;
    }

    void add(const double& addSum)
    {
        this->cSum += addSum >= 0 ? addSum : 0 ;
        ++this->changes;
    }

    void sub(const double& removeSum)
    {
        this->cSum -= removeSum >= 0 ? removeSum : 0 ;
        ++this->changes;
    }

    unsigned num()
    {
        return this->changes;
    }



};

int main()
{

    NumbersSummator mySum(12.30);
    mySum.add(20);
    mySum.sub(10);
    mySum.sub(-2);
    std::cout<<mySum.sum()<<std::endl;
    std::cout<<mySum.num()<<std::endl;

    return 0;
}



