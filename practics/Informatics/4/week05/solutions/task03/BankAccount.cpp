#include <iostream>
#include <cstring>

#include "BankAccount.hpp"

BankAccount::BankAccount()
    : name(nullptr)
    , accountNum(nullptr)
    , balance(0) {}

BankAccount::BankAccount(const BankAccount& other)
    : balance(other.balance)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->accountNum = new char[strlen(other.accountNum) + 1];
    strcpy(this->accountNum, other.accountNum);
}

BankAccount& BankAccount::operator=(const BankAccount& other)
{
    if(this != &other)
    {
        delete[] this->name;
        delete[] this->accountNum;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->accountNum = new char[strlen(other.accountNum) + 1];
        strcpy(this->accountNum, other.accountNum);
        this->balance = other.balance;
    }

    return *this;
}

BankAccount::~BankAccount()
{
    delete[] this->name;
    delete[] this->accountNum;
}