#include <iostream>
#include <cstddef>
#include <cstring>
#include <fstream>

const std::size_t NAME_SIZE = 50;
const std::size_t BARCODE_SIZE = 20;
const std::size_t MAX_NUMBER_ITEMS = 100;

struct Item {
	char name[NAME_SIZE];
	double price;
	char barcode[BARCODE_SIZE];
	unsigned int quantity;
};

struct Store {
	Item items[MAX_NUMBER_ITEMS];
	std::size_t itemsCount;
	double revenue;
};

std::size_t getItemIndexByBarcode(const Store & store, const char* barcode) {
    for (std::size_t i = 0; i < store.itemsCount; ++i) {
        if(strcmp(store.items[i].barcode, barcode) == 0)
        {
            return i;
        }
    }
    return store.itemsCount;
}

bool addItem(Store & store, const Item & item) {
    //Check if item is already present in store
    const std::size_t index = getItemIndexByBarcode(store, item.barcode);
    if(index < store.itemsCount) {
        store.items[index].quantity += item.quantity;
        return true;
    }
    //Check for space in the store
    if(store.itemsCount + 1 >= MAX_NUMBER_ITEMS)
    {
        return false;
    }
    store.items[store.itemsCount] = item;
    store.itemsCount += 1;
    return true;
}

void printItem(const Item & item)
{
    std::cout << "Name: " << item.name << std::endl;
    std::cout << "Price: " << item.price << std::endl;
    std::cout << "Barcode: " << item.barcode << std::endl;
    std::cout << "Quantity: " << item.quantity << std::endl;
}

void printItemsInStore(const Store & store)
{
    if (store.itemsCount == 0) {
        std::cout << "Store is empty\n";
        return;
    }

    for(std::size_t i = 0; i < store.itemsCount; ++i)
    {
        std::cout << "Index " << i << ": ";
        printItem(store.items[i]);
        std::cout << '\n';
    }
}

bool buyItem(Store & store, const Item & item) {
   const std::size_t index = getItemIndexByBarcode(store, item.barcode);

    if(index < store.itemsCount) {
        // The item exists in the store
        if(item.quantity <= store.items[index].quantity) {
            store.items[index].quantity -= item.quantity;
            store.revenue += item.quantity * store.items[index].price;
            return true;
        }
    }
    return false;
}

void serialize(const Item & item, std::ofstream& fout) {
    fout << item.name << "\n";
    fout << item.barcode << "\n";
    fout << item.price << "\n";
    fout << item.quantity << "\n";
}

void serialize(const Store & store, std::ofstream& fout)
{
    fout << store.itemsCount << "\n";
    for (std::size_t i = 0; i < store.itemsCount; i++) {
        serialize(store.items[i], fout);
    }
}

void save(const Store& store) {
    std::ofstream fout;
    fout.open("ItemList.txt");
    serialize(store, fout);
    fout.close();
}

void deserialize(Store & store, std::ifstream& fin)
{
    std::size_t count;
    fin >> count;
    // while(!fin.eof())
    for(std::size_t i = 0; i < count; i++)
    {

        Item newItem;
        //Read data
        fin >> newItem.name;
        fin >> newItem.barcode;
        fin >> newItem.price;
        fin >> newItem.quantity;
        if (fin.good()) {
            addItem(store, newItem);
        }
        else {
            if (fin.fail()) {
                fin.clear();
            }
            if (fin.bad()) {

            }
            
        }
        fin.ignore();
    }
}

void read(Store & store)
{
    std::ifstream fin;  
    fin.open("ItemList.txt");
    if(fin.good())
    {
        deserialize(store, fin);
    }
    else {
        std::cout << "Could not open file for reading\n";
    }
    fin.close();
}

int main() {
    
    Store store = {};
    printItemsInStore(store);
    read(store);
    std::cout << "After read\n";
    printItemsInStore(store);
    
    /*
    Store store = {};
    Item item = { "Product1", 3.2, "123456789", 10 };
    addItem(store, item);
    addItem(store, item);

    Item item2 = { "Product2", 3.2, "1212331", 10 };
    addItem(store, item2);
    printItemsInStore(store);

    save(store);
    */
}

