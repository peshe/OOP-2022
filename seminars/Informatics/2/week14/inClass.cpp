#include <iostream>
#include <cstring>
class String {
public:
    String() : String("") {}
    String(const char* str)
    {
        this->str = new char[strlen(str)+1];
        strcpy_s(this->str, strlen(str) + 1, str);
    }
    String(const String& other)
    {
        this->copy(other);
    }
    String& operator=(const String& other)
    {
        if(this!=&other)
        {
            delete[] this->str;
            this->copy(other);
        }
        return *this;
    }
    ~String()
    {
        delete[] str; 
    }
    size_t getLen() const
    {
        return strlen(this->str);
    }
private:
    void copy(const String& other) {
        this->str = new char[strlen(other.str) + 1];
        strcpy_s(this->str, strlen(other.str) + 1, other.str);
    }
private:
    char* str;
};

template<typename T>
class C {
    T* strings[50];
    std::size_t size, capacity;
public:
    C& add(const T* const newString) {

        strings[size] = new T(*newString);
        ++size;
    }
};

class Ticket {
public:
    Ticket(const String& eventName, double price) 
        : eventName(eventName) {
        this->price = price;
    }
    virtual double getPrice() const {
        return this->price;
    }
private:
    String eventName;
    double price;
};
class GroupTicket : public Ticket {
public: 
    GroupTicket(unsigned ppl, const String& eventName, double price)
        :Ticket(eventName, price)
    {
        if(ppl<20)
        {
            throw "people must be >= 20";
        }
        pplCount = ppl;
    }
    virtual double getPrice() const override {
        return pplCount * (Ticket::getPrice() - 2); 
    }
    unsigned getPeopleCount() const {
        return this->pplCount;
    }
private:
    unsigned int pplCount;
};
void printTicketSumAndPeopleCount(Ticket** tickets, std::size_t count)
{
    double sum = 0;
    unsigned int peopleCount = 0;
    for(std::size_t i = 0; i<count;++i)
    {
        sum += tickets[i]->getPrice();
        GroupTicket* tick = dynamic_cast<GroupTicket*>(tickets[i]);
        if(tick != nullptr)
        {
            peopleCount += tick->getPeopleCount();
        }
        else
        {
            peopleCount++;
        }
    }
    std::cout << "Sum of tickets' price: "<< sum << std::endl;
    std::cout << "People count: " << peopleCount << std::endl;
}
int main() {
    GroupTicket gt(20, "Hamlet", 5);
    Ticket t("Hamlet", 5);
    Ticket* tickets[3] = { &gt, &t };
    printTicketSumAndPeopleCount(tickets, 2);
    // Sum of tickets' price 65
    // ppl count : 21
}

/*
Да се реализира клас Билет (за театрално представление), който поддържа информация
за името на постановката и цена. Всеки нормален билет важи за един зрител. Съществува
още Групов билет, който важи най-малко за 20 човека и цената му се намалява с 2 лв за
всеки човек.
Да се напише функция, която приема множество от билети (нормални и групови) за
дадено театрално представление и извежда общата стойност на билетите и броя на
зрителите.
*/
