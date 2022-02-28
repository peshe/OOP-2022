#include <iostream>

enum OperationSystem
{
    NONE = -1,
    WINDOWS,
    LINUX,
    MACOS
};

struct Laptop
{
    double price;
    char model[32];
    int sizeOfScreen;
    int capacityOfHDD;
    char videocard[32];
    bool hasSSD;
    OperationSystem operationSystem;
};

void initialize(Laptop& l)
{
    
    char os[10];
    std::cout << "Enter laptop specifications:" << std::endl;
    std::cin >> l.price >> l.model >> l.sizeOfScreen >> l.capacityOfHDD >> l.videocard >> l.hasSSD >> os;
    switch(os[0])
    {
        case 'W' : l.operationSystem = WINDOWS; break;
        case 'M' : l.operationSystem = MACOS; break;
        case 'L' : l.operationSystem = LINUX; break;
        default : l.operationSystem = NONE; break; 
    }
}

void print(const Laptop& l)
{
    std::cout << "Laptop specifications: " << std::endl;
    std::cout << l.price << std::endl;
    std::cout << l.model << std::endl;
    std::cout << l.sizeOfScreen << std::endl;
    std::cout << l.capacityOfHDD << std::endl;
    std::cout << l.videocard << std::endl;
    std::cout << l.hasSSD << std::endl;
    switch(l.operationSystem)
    {
        case WINDOWS : std::cout << "Windows" << std::endl; break;
        case LINUX : std::cout << "Linux" << std::endl; break;
        case MACOS : std::cout << "MACOS" << std::endl; break;
        default : std::cout << "None" << std::endl;
    }
}

const size_t AMOUNT_OF_LAPTOPS = 5;

void showMostExpensiveLaptop(const Laptop* laptops, const size_t size)
{
    size_t highestPrice = laptops[0].price;
    size_t index = 0;
    for(size_t i = 1; i < AMOUNT_OF_LAPTOPS; i++)
    {
        if(laptops[i].price > highestPrice)
        {
            highestPrice = laptops[i].price;
            index = i;
        }
    }
    print(laptops[index]);
}

double averagePrice(const Laptop* laptops, const size_t size)
{
    double sum = 0;
    for(size_t i = 0; i < AMOUNT_OF_LAPTOPS; i++)
    {
        sum += laptops[i].price;
    } 
    return sum / AMOUNT_OF_LAPTOPS;
}

void printLaptopsWindows(const Laptop* laptops, const size_t size)
{
    for(size_t i = 0; i < AMOUNT_OF_LAPTOPS; i++)
    {
        if(laptops[i].operationSystem == WINDOWS)
        {
            print(laptops[i]);
        }
    }
}

int main()
{
    Laptop laptops[AMOUNT_OF_LAPTOPS];
    for(size_t i = 0; i < AMOUNT_OF_LAPTOPS; i++)
    {
        initialize(laptops[i]);
    }

    showMostExpensiveLaptop(laptops, AMOUNT_OF_LAPTOPS);

    std::cout << averagePrice(laptops, AMOUNT_OF_LAPTOPS) << std::endl;

    printLaptopsWindows(laptops, AMOUNT_OF_LAPTOPS);

    return 0;
}
