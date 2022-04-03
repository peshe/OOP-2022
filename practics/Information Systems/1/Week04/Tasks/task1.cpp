#include<iostream>
#include<fstream>

class Time
{
    private:
    unsigned hours;
    unsigned minutes;

    public:
    Time()
    {
        this->hours = 0;
        this->minutes = 0;
    }

    void setHours(const unsigned& hours_)
    {
        if(hours_ >= 0 && hours <= 23)
        {
            this->hours = hours_;
        }
        else
        {
            std::cout<<"invalid hours"<<std::endl;
        }
    }

    void setMinutes(const unsigned& min)
    {
        if(min >= 0 && min <= 60)
        {
            if(min == 60)
            {
                this->minutes = 0;
                this->hours++;
            }
            else
            {
                this->minutes = min;
            }
        }
        else
        {
            std::cout<<"invalid minutes"<<std::endl;
        }
    }

    void addMinutes(const unsigned& min)
    {
        if(min >= 0 && min <= 60)
        {
            if(min == 60)// no need to change minutes
            {
                this->hours++;
            }
            else
            {
                this->minutes += min;
            }
        }
        else
        {
            std::cout<<"invalid minutes"<<std::endl;
        }
    }

    unsigned pastMinutes()
    {
        return (this->hours*60 + this->minutes);
    }

    void printTime()const
    {
        std::cout<<this->hours<<" : "<<this->minutes<<std::endl;
    }


};

int main()
{
    Time time;
    time.setHours(13);
    time.setMinutes(28);
    time.printTime();

    return 0;
}