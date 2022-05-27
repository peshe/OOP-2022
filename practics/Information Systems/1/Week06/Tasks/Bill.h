#pragma once

/*
* Напишете програма, която има клас Bill, който пази стойността на сметка. 
Добвете статична променлива, която брои броя на създадените обекти от класът Bill.
Добавете статична функция, която ви връща стойността на статичната променлива.
*/

class Bill {
private:
	double bill;

public:
	static unsigned numberOfBills;

	Bill(double _bill) : bill(_bill) {
		++numberOfBills;
	}

	static unsigned getNumberOfBills() {
		return numberOfBills;
	}
};
