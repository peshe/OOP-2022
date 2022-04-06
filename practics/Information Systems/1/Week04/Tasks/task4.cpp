#include<iostream>

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


class Alarm
{
    private:

    Time alarmTime;

    public:
    void setAlarm(const unsigned& hours_ , const unsigned& min_)
    {
        alarmTime.setHours(hours_);
        alarmTime.setMinutes(min_);
    }

    void addMinutes( const unsigned& min_)
    {
        alarmTime.addMinutes(min_);
    }

    void resetAlarm()
    {
        alarmTime.setHours(0);
        alarmTime.setMinutes(0);
    }
};




int main()
{
    Alarm alarms[3];
    alarms[0].setAlarm(12,34);
    alarms[1].setAlarm(2,34);
    alarms[2].setAlarm(9,0);


    return 0;
}