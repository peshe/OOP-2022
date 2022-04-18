#pragma once

class BankAccount
{
private:
    char* name;
    char* accountNum;
    double balance;

public:
    BankAccount();
    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);
    ~BankAccount();
};