#include <iostream>
#include <cstring>

class BankAccount {
private:
    char account_name[21];
    char account_number[11];
    double account_cash;
public:
    BankAccount() {
        strcpy(this->account_name, "");
        strcpy(this->account_number, "");
        this->account_cash = 0;
    }

    // hw: write it with setters
    BankAccount(const char* account_name, const char* account_number, double account_cash) {
        strcpy(this->account_name, account_name);
        strcpy(this->account_number, account_number);
        this->account_cash = account_cash;
    }

    void print() const {
        std::cout << this->account_name << std::endl;
        std::cout << this->account_number << std::endl;
        std::cout << "MONEY: " << this->account_cash << "$$$" << std::endl;
    }

    void deposit(double cash) {
        this->account_cash += cash;
        std::cout << "Successfully added funds - " << cash << "$" << std::endl; 
    }

    void withdraw(double cash) {
        this->account_cash -= cash;
        std::cout << "Withdrawn " << cash << "$" << std::endl; 
    }
};

int main() {
    BankAccount bank("FMI Bank", "BG954789752198416316", 5000);
    bank.withdraw(1000);
    bank.print();
    bank.deposit(2000);
    bank.print();
}