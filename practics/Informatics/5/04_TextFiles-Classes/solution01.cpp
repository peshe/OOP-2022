#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

const size_t CapacityNumber = 16;
const size_t CapacityName   = 24;

class BankAccount {

private:

	double balance;
	char   accountNumber[CapacityNumber];
	char   name[CapacityName];

public:

	// извежда на екрана на екрана банкова сметка
	void print()const;

	// внася пари от банкова сметка
	bool paymentOfAnAmount(double amount);

	// тегли пари от банкова сметка
	bool drawOfAnAmount(double amount);

	// прочитане на банковата сметка от текстов файл
	void read(ifstream& fin);

	// записване на банковата сметка в текстов файл
	void write(ofstream& fout)const;

	// set метод за balance
	void setBalance(double newBalance);

	// set метод за bank account number
	void setAccountNumber(const char* newAccountNumber);

	// set метод за name of client
	void setName(const char* newName);

	// get метод за balance
	double getBalance()const;

	// get метод за bank account number
	const char* getAccountNumber()const;

	// get метод за name of client
	const char* getName()const;
};

void BankAccount::print()const {

	cout << "Client: " << name << endl
		 << "Bank account number: " << accountNumber << endl
		 << "Balance: " << balance << endl;
}

bool BankAccount::paymentOfAnAmount(double amount) {

	if (amount < 0) return false;

	balance = balance + amount;

	return true;
}

bool BankAccount::drawOfAnAmount(double amount) {

	if (amount < 0 || amount <= balance) return false;

	balance = balance - amount;

	return true;
}

void BankAccount::read(ifstream& fin) {

	char ch;
	size_t cnt = 0;
	char inputName[CapacityName];

	while (fin.get(ch) && !fin.eof() && ch != '\n' && ch != ' ' && cnt < CapacityName) {

		inputName[cnt] = ch;
		++cnt;
	}

	inputName[cnt] = '\0';

	strcpy_s(name, CapacityName, inputName);


	cnt = 0;

	char inputAccountNumber[CapacityNumber];

	while (fin.get(ch) && !fin.eof() && ch != '\n' && ch != ' ' && cnt < CapacityNumber) {

		inputAccountNumber[cnt] = ch;
		++cnt;
	}

	inputAccountNumber[cnt] = '\0';

	strcpy_s(accountNumber, CapacityNumber, inputAccountNumber);


	double inputBalance;
	do {

		fin >> inputBalance;

	} while (inputBalance < 0);

	balance = inputBalance;
}

void BankAccount::write(ofstream& fout)const {

	fout << "Client: " << name << endl
		 << "Bank account number: " << accountNumber << endl
		 << "Balance: " << balance << endl;
}

void BankAccount::setBalance(double newBalance) {

	if (newBalance < 0) {
		balance = 5;

	} else {
		balance = newBalance;
	}
}

void BankAccount::setAccountNumber(const char* newAccountNumber) {

	strcpy_s(accountNumber, CapacityNumber, newAccountNumber);
	accountNumber[CapacityNumber - 1] = '\0';
}

void BankAccount::setName(const char* newName) {

	strcpy_s(name, CapacityName, newName);
	name[CapacityName - 1] = '\0';
}

double BankAccount::getBalance()const {

	return balance;
}

const char* BankAccount::getAccountNumber()const {

	return accountNumber;
}

const char* BankAccount::getName()const {

	return name;
}

int main() {

	return 0;
}
