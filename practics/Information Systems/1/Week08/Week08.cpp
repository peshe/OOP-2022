#include <iostream>

class MyString {
private:
    char* myString;
    unsigned size;
    unsigned capacity;

    void copy(const MyString& myString);
    void erase();
    void resize();

public:
    MyString();
    MyString(const char* myString, const unsigned& size);
    MyString(const MyString& myString);
    MyString& operator=(const MyString& myString);
    ~MyString();

    const char* getMyString() const;
    void setMyString(const char* newString, const unsigned& size);
    void pushBack(const char element);
    void pushFront(const char element);
    void pushInPosition(const char element, const unsigned& posistion);

    MyString operator+(const MyString& rhs) const;
    MyString& operator+=(const MyString& rhs);

    bool operator<(const MyString& rhs) const;
    bool operator>(const MyString& rhs) const;
    bool operator<=(const MyString& rhs) const;
    bool operator>=(const MyString& rhs) const;
    bool operator==(const MyString& rhs) const;
    bool operator!=(const MyString& rhs) const;

    const char operator[](unsigned index) const;
    char operator[](unsigned index);

    friend std::istream& operator>>(std::istream& in, MyString& obj);
    friend std::ostream& operator<<(std::ostream& out, const MyString& obj);
};

void MyString::copy(const MyString& rhs)
{
    size = rhs.size;
    capacity = rhs.capacity;
    myString = new char[capacity];
    for (unsigned i = 0; i < size; ++i)
    {
        myString[i] = rhs.myString[i];
    }
}

void MyString::resize()
{
    capacity *= 2;
    char* newArr = new char[capacity];
    for (unsigned i = 0; i < size; ++i)
    {
        newArr[i] = myString[i];
    }
    erase();
    myString = newArr;
}

void MyString::erase()
{
    delete[] myString;
}

MyString::MyString()
{
    capacity = 8;
    myString = new char[capacity];
    size = 0;
}

MyString::MyString(const char* newString, const unsigned& size)
{
    setMyString(newString, size);
}

MyString::MyString(const MyString& rhs)
{
    copy(rhs);
}

MyString& MyString::operator=(const MyString& rhs)
{
    if (this != &rhs)
    {
        erase();
        copy(rhs);
    }

    return *this;
}

MyString::~MyString()
{
    erase();
}

const char* MyString::getMyString() const {
    return myString;
}

void MyString::setMyString(const char* newString, const unsigned& size) {
    this->size = size;
    capacity = size * 2;
    myString = new char[capacity];
    for (unsigned i = 0; i < size; ++i)
    {
        myString[i] = newString[i];
    }
}

void MyString::pushBack(const char element) {
    if (size >= capacity)
    {
        resize();
    }
    myString[size++] = element;
}

void MyString::pushFront(const char element) {
    if (size >= capacity)
    {
        resize();
    }
    char* newString = new char[capacity];
    ++size;
    newString[0] = element;

    for (unsigned i = 1; i < size; ++i)
    {
        newString[i] = myString[i];
    }

    erase();
    setMyString(newString, size);
}

void MyString::pushInPosition(const char element, const unsigned& posistion) {
    if (size >= capacity)
    {
        resize();
    }
    char* newString = new char[capacity];
    ++size;

    unsigned index = 0;

    for (unsigned i = 0; i < size; ++i)
    {
        if (posistion == i) {
            newString[i] = element;
            continue;
        }
        newString[i] = myString[index++];
    }

    erase();
    setMyString(newString, size);
}

MyString MyString::operator+(const MyString& rhs) const {
    MyString result;
    result.size = size * rhs.size;
    result.myString = new char[result.size + 1];
    result.capacity = result.size * 2;

    unsigned index = 0;
    for (unsigned i = 0; i < size; ++i) {
        result.myString[index++] = myString[i];
    }

    for (unsigned i = 0; i < rhs.size; ++i) {
        result.myString[index++] = rhs.myString[i];
    }

    return result;
}

MyString& MyString::operator+=(const MyString& rhs) {
    *this = *this + rhs;
    return *this;
}

bool MyString::operator<(const MyString& rhs) const {
    for (unsigned i = 0; i < size; ++i)
    {
        if (myString[i] >= rhs.myString[i])
        {
            return false;
        }
    }
    return true;
}

bool MyString::operator>(const MyString& rhs) const {
    return rhs < (*this);
}

bool MyString::operator<=(const MyString& rhs) const {
    return (*this < rhs) || (*this == rhs);
}

bool MyString::operator>=(const MyString& rhs) const {
    return (*this > rhs) || (*this == rhs);
}

bool MyString::operator==(const MyString& rhs) const {
    for (unsigned i = 0; i < size; ++i)
    {
        if (myString[i] != rhs.myString[i])
        {
            return false;
        }
    }
    return true;
}

bool MyString::operator!=(const MyString& rhs) const {
    return !(*this == rhs);
}

const char MyString::operator[](unsigned index) const {
    if (index > size) {
        std::cout << "Invalid index" << std::endl;
        return '-';
    }

    return myString[index];
}

char MyString::operator[](unsigned index) {
    if (index > size) {
        std::cout << "Invalid index" << std::endl;
        return '-';
    }

    return myString[index];
}

std::istream& operator>>(std::istream& in, MyString& obj)
{
    std::cout << "Input size: ";
    in >> obj.size;
    for (unsigned i = 0; i < obj.size; ++i)
    {
        in >> obj.myString[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const MyString& obj)
{
    for (unsigned i = 0; i < obj.size; ++i)
    {
        out << obj.myString[i];
    }
    return out;
}


int main()
{
    return 0;
}
