#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const size_t MaxSize = 1024;

class Stack {

private:

	int  top;
	char items[MaxSize];

public:

	// добавя във върха символ, ако не е пълен
	void push(char ch);

	// изтрива върха на стека, ако не е празен
	char pop();

	// проверява дали стека е празен
	bool isEmpty()const;

	// проверява дали стека е пълен
	bool isFull()const;

	// извежда елементите на стека
	void print()const;

	// set метод за елементите на стека
	void setItems(const char* newItems);

	// set метод за върха на стека
	void setTop(int newTop);

	// get метод за елементите на стека
	const char* getItems()const;

	// get метод за върха на стека
	int getTop()const;
	
};

void Stack::push(char ch) {

	if (isFull()) {

		cout << "The stack is full.\n";
		return;
	}

	++top;
	items[top] = ch;
	items[top + 1] = '\0';
}
 
char Stack::pop() {

	if (isEmpty()) {

		cout << "The stack is empty.\n";
		return '\0';
	}

	return items[top--];
}

bool Stack::isEmpty()const {

	return top == -1;
}

bool Stack::isFull()const {

	return top == MaxSize - 1;
}

void Stack::print()const {

	for (int i = 0; i < top; ++i) {
		cout << items[i];
	}
	cout << endl;
}

void Stack::setItems(const char* newItems) {

	int len = strlen(newItems);

	for (int i = 0; i < len && len < MaxSize; ++i) {
		items[i] = newItems[i];
	}

	items[len] = '\0';
}

void Stack::setTop(int newTop) {

	if (newTop < 0) {
		
		top = 0;
	} else {
		top = newTop;
	}
}

const char* Stack::getItems()const {

	return items;
}

int Stack::getTop()const {

	return top;
}


int main() {

	return 0;
