#include <iostream>
#include <cassert>
struct S {};
template<typename T>
void input(T* arr, std::size_t n) {
	for (std::size_t i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
}

void test81() {
	int intArr[12];
	double dArr[6];
	input(intArr, 5);
	input<double>(dArr, 6);
	// S ss[5];
	// input(ss, 5);


	for (std::size_t i = 0; i < 5; ++i) {
		std::cout << intArr[i] << " ";
	}
	for (std::size_t i = 0; i < 6; ++i) {
		std::cout << dArr[i] << " ";
	}
}


template<typename C>
bool ordered(C* arr, std::size_t n)
{
	for (std::size_t i = 1; i < n; ++i)
	{
		if ((arr[i - 1] < arr[i]) == false)
		{
			return false;
		}
	}
	return true;
}

void test82() {
	int intArr[5];
	input(intArr, 5);
	std::cout << std::boolalpha << ordered(intArr, 5);

}

template<typename T>
bool member(T* arr, std::size_t n, const T &x) {
	for (std::size_t i = 1; i < n; ++i) {
		if (arr[i] == x) {
			return true;
		}
	}
	return false;
}

void test83() {
	int arr[5];
	input(arr, 5);
	std::cout << std::boolalpha << member(arr, 5, 3);
}




template<typename T>
class DynArray {
	static const std::size_t INITIAL_CAPACITY = 8;
	T* elements;
	std::size_t size, capacity;
public:
	DynArray(std::size_t capacity = INITIAL_CAPACITY)
	{
		this->capacity = capacity;
		this->size = 0;
		this->initElements(capacity);
	}

	DynArray(const DynArray& other)
	{
		this->copy(other);
	}

	DynArray& operator=(const DynArray& other)
	{
		if (this != other)
		{
			this->destroy();
			this->copy(other);
		}
		return *this;
	}

	~DynArray()
	{
		this->destroy();
	}

	void pushBack(const T& element)
	{
		if (this->size == this->capacity)
		{
			this->resize();
		}
		this->elements[this->size] = element;
		this->size++;
	}

	T& operator[](const unsigned int index)
	{
		return this->elements[index];
	}
	const T& operator[](const unsigned int index) const 
	{
		return this->elements[index];
	}

private:
	void initElements(std::size_t capacity)
	{
		this->elements = new T[capacity];
	}
	
	void copy(const DynArray& other)
	{
		this->capacity = other.capacity;
		this->initElements(other.capacity);
		this->size = other.size;
		for (std::size_t i = 0; i < other.size; ++i)
		{
			this->elements[i] = other.elements[i];
		}
	}

	void destroy()
	{
		delete[] this->elements;
	}

	void resize()
	{
		this->capacity *= 2;
		T* newElements = new T[this->capacity];
		for (std::size_t i = 0; i < this->size; ++i)
		{
			newElements[i] = std::move(this->elements[i]);
		}
		delete[] this->elements;
		this->elements = newElements;
	}
};


int main() {
	DynArray<int> arr;
	std::size_t num;
	std::cin >> num;
	for (std::size_t i = 0; i < num; ++i)
	{
		std::cin >> arr[i];
	}
}
