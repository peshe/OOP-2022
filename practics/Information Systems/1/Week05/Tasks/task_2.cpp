#include<iostream>
#include<cstring>
#include<string>

class Word
{
    private:

    char* word_a;
    unsigned size;

    public:

    Word()
    {
        this->word_a = nullptr;
        this->size = 0;
    }

    Word(const char* word_cpy)
    {
        if(word_cpy == nullptr)
        {
            this->word_a = nullptr;
            this->size = 0;
            std::cout<<"invalid argument"<<std::endl;
            return;
        }
        int len = 0;
        for( ; word_cpy[len] != '\0' ; ++len)
        {}
        this->word_a = new char[len+1];
        if(this->word_a == nullptr)
        {
            std::cout<<"couldnt allocate memory"<<std::endl;
            return;
        }
        for(int i =0 ;i < len ;++i)
        {
            this->word_a[i] = word_cpy[i];
        }
        this->size = len;
    }

    Word(const Word& other)
    {
        if(other.word_a != nullptr)
        {
            this->word_a = new char[other.size + 1];
            if(this->word_a != nullptr)
            {
                for(int i = 0; i < other.size ; ++i)
                {
                    this->word_a[i] = other.word_a[i];
                }
                this->size = other.size;
                return;
            }
            this->size = 0;
            std::cout<<"couldnt allocate memory"<<std::endl;
            return;

        }
        this->word_a = nullptr;
        this->size = 0;
        std::cout<<"couldnt allocate memory"<<std::endl;
        return;
    }

    ~Word()
    {
        if(this->word_a != nullptr)
        {
            delete[] this->word_a;
        }
    }

    char getElementOnPosition(const int& position)
    {
        if(this->word_a == nullptr || position > this->size)
        {
            std::cout<<"invalid argument"<<std::endl;
        }

        for(int i =0 ; i < size ; ++i)
        {
            if(i == position)
            {
                return this->word_a[i];
            }
        }
    }

    void addSymbol(const char& s)
    {
        if(this->word_a != nullptr)
        {
            char* word_cpy = new char[this->size + 2];
            if(word_cpy != nullptr)
            {   
                int i =0;
                for( ; i < this->size ; ++i)
                {
                    word_cpy[i] = this->word_a[i];
                }
                word_cpy[i] = s;
                delete[] this->word_a;
                this->word_a = word_cpy;
                this->size++;
                return;
            }
            std::cout<<"couldnt allocate memory"<<std::endl;
            return;
        }
        this->word_a = new char[2];
        if(this->word_a != nullptr)
        {
            this->word_a[0] = s;
            this->size++;
            return;
        }
        std::cout<<"couldnt allocate memory"<<std::endl;
    }

    bool biggerThan(const Word& other)
    {
        if(this->word_a == nullptr)
        {
            return false;
        }
        else if(other.word_a == nullptr)
        {
            return true;
        }
        
        for(int i = 0 ; i < this->size && i < other.size ; ++i)
        {
            if(this->word_a[i] > other.word_a[i])
            {
                return true;
            }
            else if(this->word_a[i] < other.word_a[i])
            {
                return false;
            }
        }

        if(this->size > other.size)
        {
            return true;
        }

        return false;

    }
};

int main()
{
    Word myWord;

    Word mySecondWord(myWord);

    return 0;
}