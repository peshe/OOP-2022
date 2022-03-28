#include <iostream>
#include <string>

const size_t SIZE     = 16;
const size_t CAPACITY = 6;

enum class Colors {

    Red,    // 0
    Orange, // 1
    Green,  // 2 
    Blue,   // 3
    Yellow  // 4
};

enum class TypeFruit {

    OneYearOld, // 0
    Perennial,  // 1
    Tropical    // 2
};

struct Fruit {

    char      name[SIZE];
    Colors    color;
    TypeFruit type;
};

void createFruit(Fruit& fruit) {

    char input[SIZE]{ '\0' };
    std::cin.getline(input, SIZE);

    std::cin.getline(input, SIZE);
    if (!strcmp(input, "red")) {
        fruit.color = Colors::Red;
    } else if (!strcmp(input, "orange")) {
        fruit.color = Colors::Orange;
    } else if (!strcmp(input, "green")) {
        fruit.color = Colors::Green;
    } else if (!strcmp(input, "blue")) {
        fruit.color = Colors::Blue;
    } else if (!strcmp(input, "yellow")) {
        fruit.color = Colors::Yellow;
    } else { // if input is wrong the default value will be yellow
        fruit.color = Colors::Yellow;
    }

    std::cin.getline(input, SIZE);
    if (!strcmp(input, "oneYearOld")) {
        fruit.type = TypeFruit::OneYearOld;
    } else if (!strcmp(input, "perennial")) {
        fruit.type = TypeFruit::Perennial;
    } else if (!strcmp(input, "tropical")) {
        fruit.type = TypeFruit::Tropical;
    } else { // if input is wrong the default value will be one year old
        fruit.type = TypeFruit::OneYearOld;
    }
}

// създаване на едномерен масив от плодове
void createFruitsArray(Fruit arr[], const size_t& size) { 

    for (size_t i = 0; i < size; ++i) {
        createFruit(arr[i]);
    }
}

void printFruit(const Fruit& fruit) {

    std::cout << "Name of fruit: " << fruit.name << std::endl;

    if (fruit.type == TypeFruit::OneYearOld) {

        std::cout << "Type of fruit: one year old\n";

    } else  if (fruit.type == TypeFruit::Perennial) {

        std::cout << "Type of fruit: one perennial\n";

    } else if (fruit.type == TypeFruit::Tropical) {

        std::cout << "Type of fruit: tropical\n";

    } else {
        std::cout << "Invalid type of fruit!\n";
    }


    if (fruit.color == Colors::Red) {

        std::cout << "Color of fruit: red\n";

    } else  if (fruit.color == Colors::Orange) {

        std::cout << "Color of fruit: orange\n";

    } else if (fruit.color == Colors::Green) {

        std::cout << "Color of fruit: green\n";

    } else if (fruit.color == Colors::Blue) {

        std::cout << "Color of fruit: blue\n";

    } else if (fruit.color == Colors::Yellow) {

        std::cout << "Color of fruit: yellow\n";

    } else {
        std::cout << "Invalid color of fruit!\n";
    }
}

// извеждане на едномерен масив от плодове
void printFruits(const Fruit arr[], size_t size) {

    for (size_t i = 0; i < size; ++i) {
        printFruit(arr[i]);
        std::cout << std::endl;
    }
}

// сортиране в масива във възходящ ред по име на плода
bool isAscendingOrder(const char str1[], const char str2[]) {

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    for (size_t i = 0; i != len1 && i != len2; ++i) {
        
        if (str2[i] < str1[i]) {
            return false;
        }
    }

    return true;
}

// сортиране в масива в низходящ ред по име на плода
bool isDescendingOrder(const char str1[], const char str2[]) {

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    for (size_t i = 0; i != len1 && i != len2; ++i) {

        if (str2[i] > str1[i]) {
            return false;
        }
    }

    return true;
}

void swapFruits(Fruit& f1, Fruit& f2) {

    Fruit temp; 
    strcpy_s(temp.name, SIZE, f1.name);
    temp.color = f1.color;
    temp.type  = f1.type;

    strcpy_s(f1.name, SIZE, f2.name);
    f1.color = f2.color;
    f1.type  = f2.type;

    strcpy_s(f2.name, SIZE, temp.name);
    f2.color = temp.color;
    f2.type  = temp.type;
}

// извежда едногодишните плодове с даден цвят, записани в масива, сортирани в масива във възходящ ред по име на плода
void OneYearOldWithColor(Fruit arr[], size_t size, const Colors& givenColor) {
    
    //  сортираме във възходящ ред по име на плода
    bool isSwap;
    for (size_t i = 0; i < size - 1; ++i) {

        isSwap = false;
        for (size_t j = 0; j < size - i - 1; ++j) {

            if (isAscendingOrder(arr[j].name, arr[j + 1].name)) {
               
                swapFruits(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap) {
            break;
        }
    }


    // извежда едногодишните плодове с даден цвят
    for (size_t i = 0; i < size; ++i) {

        if (arr[i].type == TypeFruit::OneYearOld && arr[i].color == givenColor) {
            printFruit(arr[i]);
            std::cout << std::endl;
        }
    }
}

// извежда многогодишните, тропически плодове с даден цвят, сортирани в низходящ ред по име на плода
void perennialTropicalWithColor(Fruit arr[], size_t size, const Colors& givenColor) {

    // сортираме в низходящ ред по име на плода
    bool isSwap;
    for (size_t i = 0; i < size - 1; ++i) {

        isSwap = false;
        for (size_t j = 0; j < size - i - 1; ++j) {

            if (isDescendingOrder(arr[j].name, arr[j + 1].name)) {

                swapFruits(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap) {
            break;
        }
    }


    // извежда многогодишните, тропически плодове плодове с даден цвят
    for (size_t i = 0; i < size; ++i) {

        if (arr[i].color == givenColor && (arr[i].type == TypeFruit::Perennial || arr[i].type == TypeFruit::Tropical)) {
            printFruit(arr[i]);
            std::cout << std::endl;
        }
    }
}

int main() {

    Fruit fruits[CAPACITY];

    return 0;
}
