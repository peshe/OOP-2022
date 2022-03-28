#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

const int MaxProducts = 10;

class Product
{
private:
    char name[32];
    double price;
    int expiryDays;
    double fat;
    bool isFood;
public:
    void setName(const char* name)
    {
        strcpy(this->name,name);
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    void setExpiryDays(int expiryDays)
    {
        this->expiryDays = expiryDays;
    }
    void setFat(double fat)
    {
        this->fat = fat;
    }
    void setIsFood(bool isFood)
    {
        this->isFood = isFood;
    }

    const char* getName()const
    {
        return this->name;
    }
    double getPrice()const
    {
        return this->price;
    }
    int getExpiryDays()const
    {
        return this->expiryDays;
    }
    double getFat()const
    {
        return this->fat;
    }
    bool getIsFood()const
    {
        return this->isFood;
    }
    
    Product()
    {
        setName(" ");
        setPrice(0.0);
        setExpiryDays(0);
        setFat(0.0);
        setIsFood(0);
    }

    Product(const char* name, double price, int expiryDays, double fat, bool isFood)
    {
        setName(name);
        setPrice(price);
        setExpiryDays(expiryDays);
        setFat(fat);
        setIsFood(isFood);
    }

    void printProduct()const
    {
        cout << "\nProduct name: " << name << endl;
        cout << "Product price: " << price << " $" << endl;
        cout << "Expires in " << expiryDays << " days!" << endl;
        cout << "Fat percentage: " << fat << "%" << endl;
        cout << "This product is food: " << std::boolalpha << isFood << endl;
    }

};

class Store
{
private:
    int numOfProducts;
    int revenue;
    Product products[MaxProducts];
public:
    void setNumOfProducts(int numOfProducts)
    {
        this->numOfProducts = numOfProducts;
    }
    void setRevenue(int revenue)
    {
        this->revenue = revenue;
    }
    void setProducts(const Product products[])
    {
        for(int i = 0; i < this->numOfProducts; i++)
        {
            this->products[i] = products[i]; // при наличие на предифиниран operator=
        }
    }

    int getNumOfProducts()const
    {
        return this->numOfProducts;
    }
    int getRevenue()const
    {
        return this->revenue;
    }
    void showProducts() const
    {
        for(int i = 0; i < this->numOfProducts; i++)
        {
            products[i].printProduct();
        }
    }
    // const Product* getProducts() const {
    //     // const returnProducts Products[10]
    //     // for (this->products) returnProducts[i] = this->products[i]
    //     // return returnProducts; 
    // }
    Store()
    {  
        setNumOfProducts(-1);
        setRevenue(-1);
        // setProducts();
    }

    Store(int numOfProducts, int revenue)
    {
        setNumOfProducts(numOfProducts);
        setRevenue(revenue);
        // setProducts();
    }

    void searchByName(const char* name)
    {
        for(int i = 0; i < numOfProducts; i++)
        {
            if(strcmp(products[i].getName(),name) == 0)
            {
                products[i].printProduct();
                cout << "__________________________";
            }
        }
    }

    double calcLosses()
    {
        double losses = 0;
        for(int i = 0; i < numOfProducts; i++)
        {
            if(products[i].getExpiryDays() <= 0) losses += products[i].getPrice();
        }

        this->revenue -= losses;
        return losses;
    }

    void sellProduct(int index) //const char *name, const Product& product
    {
        if(index >= numOfProducts)
        {
            cout << "No product!" << endl;
            return;
        }

        //Finding and printing the item
        for(int i = 0; i < numOfProducts; i++)
        {
            if(index == i) // if(strcmp(name, products[i].getName()) == 0)
            {
                cout << "Sell product: " << products[i].getName() << endl;
            } 
        }

        // A, B, C, anabol, D -> remove index=3
        // A, B, C, D ?


        //Moving the rest of the elements in the array 1 position to the left
        for(int i = index; i + 1 != numOfProducts; i++)
        {
            products[i] = products[i+1]; // още веднъж предефинирано operator=
        }

        // A, B, C, D, D -> (default values)
    }
};

int main()
{
    return 0;
}