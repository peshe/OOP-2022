#include<iostream>

class Triangle
{
    private:

    unsigned sideA , sideB , sideC;

    public:
    Triangle()
    {
        this->sideA = 0;
        this->sideB = 0;
        this->sideC = 0;
    }

    bool correctSides(const unsigned& firstSide ,const unsigned& secondSide,const unsigned& thirdSide )
    {
        return (firstSide < secondSide + thirdSide && secondSide < firstSide + thirdSide && thirdSide < firstSide + secondSide);
    }   

    void setSideA(const unsigned& side)
    {
        if(correctSides(side , sideB , sideC))
        {
            this->sideA = side;
        }
        else
        {
            std::cout<<"incorrect side value"<<std::endl;
        }
    }

    void setSideB(const unsigned& side)
    {
        if(correctSides(sideA , side , sideC))
        {
            this->sideB = side;
        }
        else
        {
            std::cout<<"incorrect side value"<<std::endl;
        }
    }

    void setSideC(const unsigned& side)
    {
        if(correctSides(sideA , sideB , side))
        {
            this->sideC = side;
        }
        else
        {
            std::cout<<"incorrect side value"<<std::endl;
        }
    }

    unsigned getSideA()
    {
        return this->sideA;
    }

    unsigned getSideB()
    {
        return this->sideB;
    }

    unsigned getSideC()
    {
        return this->sideC;
    }

    unsigned perimeter()
    {
        return this->sideA + this->sideB + this->sideC;
    }

    std::string triangleType()
    {
        std::string type;
        if(this->sideA == this->sideB && this->sideA == this->sideC)
        {
            type = "equilateral triangle";
        }
        else if( this->sideA == this->sideB || this->sideA == this->sideC || this->sideB == this->sideC)
        {
            type = "isosceles triangle";
        }
        else
        {
            type = "scalene triangle";
        }
        return type;
    }

};


int main()
{

    return 0;
}