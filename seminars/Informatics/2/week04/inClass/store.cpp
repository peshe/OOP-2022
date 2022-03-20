#include <iostream>
#include <cstddef>
#include <cstring>
#include <fstream>

const std::size_t NAME_SIZE = 50;
const std::size_t BARCODE_SIZE = 20;
const std::size_t MAX_NUMBER_ITEMS = 100;

class Item {
private:
	char name[NAME_SIZE];
    std::string nameString;
	double price; // VERY bad
	char barcode[BARCODE_SIZE];
	unsigned int quantity;

public:

    void setName(const char* name)
    {
        strcpy_s(this->name, NAME_SIZE, name);
        // strcpy(this->name, name); // Ако не се ползва на M$ функцията
    }
    
    double getPrice() const {
        return this->price;
    }

    void setPrice(double price)
    {
        this->price = price;
    }

    const char* getBarcode() const {
        return this->barcode;
    }

    void setBarcode(const char* barcode)
    {
        strcpy_s(this->barcode, BARCODE_SIZE, barcode); 
    }

    unsigned int getQuantity() const {
        return this->quantity;
    }

    void setQuantity(unsigned int newQuantity) {
        this->quantity = newQuantity;
    }

    void increaseQuantity(unsigned int increase) {
        this->quantity += increase;
    }

    void decreaseQuantity(unsigned int decrease) {
        this->quantity -= decrease;
    }

    void printItem()
    {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Price: " << this->price << std::endl;
        std::cout << "Barcode: " <<  this->barcode << std::endl;
        std::cout << "Quantity: " <<  this->quantity << std::endl;
    }

    void serialize(std::ofstream& fout) {
        fout << this->name << "\n";
        fout << this->barcode << "\n";
        fout << this->price << "\n";
        fout << this->quantity << "\n";
    }
};

/*
void Item::serialize(std::ofstream& fout) {
    fout << this->name << "\n";
    fout << this->barcode << "\n";
    fout << this->price << "\n";
    fout << this->quantity << "\n";
}
*/


class Store {
	Item items[MAX_NUMBER_ITEMS];
	std::size_t itemsCount;
	double revenue; // VERY bad

public:
    std::size_t getItemIndexByBarcode(const char* barcode) {
        for (std::size_t i = 0; i < this->itemsCount; ++i) {
            if (strcmp(this->items[i].getBarcode(), barcode) == 0)
            {
                return i;
            }
        }
        return this->itemsCount;
    }

    bool addItem(const Item& item) {
        //Check if item is already present in store
        const std::size_t index = this->getItemIndexByBarcode(item.getBarcode());
        if (index < this->itemsCount) {
            /* When using setQuantity():
            unsigned int oldQuantity = items[index].getQuantity();
            unsigned int newQuantity = oldQuantity + item.getQuantity();

            items[index].setQuantity(newQuantity);
            */
            items[index].increaseQuantity(item.getQuantity());

            return true;
        }
        //Check for space in the store
        if (this->itemsCount + 1 >= MAX_NUMBER_ITEMS)
        {
            return false;
        }
        this->items[this->itemsCount] = item;
        this->itemsCount += 1;
        return true;
    }

    void printItemsInStore()
    {
        if (this->itemsCount == 0) {
            std::cout << "Store is empty\n";
            return;
        }

        for (std::size_t i = 0; i < this->itemsCount; ++i)
        {
            std::cout << "Index " << i << ": ";
            this->items[i].printItem();
            std::cout << '\n';
        }
    }

    bool buyItem(Store& store, const Item& item) {
        const std::size_t index = getItemIndexByBarcode(item.getBarcode());

        if (index < store.itemsCount) {
            // The item exists in the store
            if (item.getQuantity() <= store.items[index].getQuantity()) {

                store.items[index].decreaseQuantity(item.getQuantity());

                store.revenue += item.getQuantity() * store.items[index].getPrice();
                return true;
            }
        }
        return false;
    }

    void serialize(const Store& store, std::ofstream& fout)
    {
        fout << store.itemsCount << "\n";
        for (std::size_t i = 0; i < store.itemsCount; i++) {
            items[i].serialize(fout);
        }
    }

    void deserialize(std::ifstream& fin)
    {
        std::size_t count;
        fin >> count;
        // while(!fin.eof())
        for (std::size_t i = 0; i < count; i++)
        {
            Item newItem;
            //Read data
            char str[NAME_SIZE];
            fin >> str;
            newItem.setName(str);
            fin >> str;
            newItem.setBarcode(str);
            double price;
            fin >> price;
            newItem.setPrice(price);
            int quantity;
            fin >> quantity;
            newItem.setQuantity(quantity);


            if (fin.good()) {
                this->addItem(newItem);
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
};
/*
void save(const Store& store) {
    std::ofstream fout;
    fout.open("ItemList.txt");
    serialize(store, fout);
    fout.close();
}

void read(Store& store)
{
    std::ifstream fin;
    fin.open("ItemList.txt");
    if (fin.good())
    {
        deserialize(store, fin);
    }
    else {
        std::cout << "Could not open file for reading\n";
    }
    fin.close();
}
*/
int main() {
    /*
    Store store = {};
    /*
    store.getItemIndexByBarcode("123456");

    const Item item;

    const char* anItemsBarcode = item.getBarcode();

    unsigned int aQuantity = item.getQuantity();
    aQuantity = 500;
    */
    /*
    printItemsInStore(store);
    read(store);
    std::cout << "After read\n";
    printItemsInStore(store);
    */

    Store store = {};
    Item item;
    item.setName("Product1");
    item.setPrice(3.2);
    item.setBarcode("123456789");
    item.setQuantity(10);

    store.addItem(item);
    


    store.printItemsInStore();


    store.addItem(item);
    
    store.printItemsInStore();

    // save(store);
    
}

