#include<iostream>
#include<cstring>

struct Article
{
    char name[31];
    double price;
};

void swapArticles(Article &firstArt, Article &secondArt)
{
    Article helper;
    std::strcpy(helper.name, firstArt.name);
    helper.price = firstArt.price;

    std::strcpy(firstArt.name, secondArt.name);
    firstArt.price = secondArt.price;

    std::strcpy(secondArt.name, helper.name);
    secondArt.price = helper.price;
}

class Shop
{
    private:

    Article articles[100];
    unsigned size;

    public:

    void setSize(const unsigned int& size_)
    {
        size = size_ >= 0 ? size_ : 0;
    }

    void enterArticles()
    {
        if(size == 0)
        {
            std::cout<<"no articles in the shop"<<std::endl;
            return;
        }

        for(int i = 0 ; i < size ; ++i)
        {
            std::cout<<"enter article " << i << " name:";
            std::cin.getline(articles[i].name , 30);

            do
            {
                std::cout << "enter article " << i << " price:";
                std::cin >> articles[i].price;
            } while (articles[i].price <= 0);
            std::cin.ignore();
        }
    }

    int getSize()
    {
        return size;
    }

    Article* maxPriceArticle()
    {
        if(size == 0)
        {
            std::cout<<"no articles in the shop"<<std::endl;
            return nullptr;
        }

        double maxPrice = INT8_MIN; 
        Article* ptrToMaxPriceArticle = nullptr;
        for(int i = 0 ; i < size ; ++i)
        {
            if(articles[i].price > maxPrice)
            {
                maxPrice = articles[i].price;
                ptrToMaxPriceArticle = &articles[i];
            }
        }
        return ptrToMaxPriceArticle;
    }

    Article* minPriceArticle()
    {
        if(size == 0)
        {
            std::cout<<"no articles in the shop"<<std::endl;
            return nullptr;
        }

        double minPrice = INT8_MAX; 
        Article* ptrToMinPriceArticle = nullptr;
        for(int i = 0 ; i < size ; ++i)
        {
            if(articles[i].price < minPrice)
            {
                minPrice = articles[i].price;
                ptrToMinPriceArticle = &articles[i];
            }
        }
        return ptrToMinPriceArticle;
    }

    Article* sortedArticles()
    {
        if(size == 0)
        {
            std::cout<<"no articles in the shop"<<std::endl;
            return nullptr;
        }
        Article* sorted = new Article[size];
        for(int i = 0 ; i < size ; ++i)
        {
           std::strcpy(sorted[i].name , articles[i].name);

           std::cout<<sorted[i].name<<std::endl;
           sorted[i].price = articles[i].price;
           
        }

        for(int i = 0 ; i < size - 1 ; ++i)
        {
            for(int j = 0 ; j < size - i - 1 ; ++j)
            {
                if(sorted[j].price > sorted[j+1].price)
                {
                    swapArticles(sorted[j] , sorted[j+1]);
                }
            }
        }

        return sorted;

    }


};


int main()
{

    Shop myShop;
    myShop.setSize(3);
    myShop.enterArticles();
    Article *maxPtr = myShop.maxPriceArticle();

    if (maxPtr != nullptr)
    {
        std::cout << "maxPrice article: " << maxPtr->name << " , " << maxPtr->price << std::endl;
    }

    Article* minPtr = myShop.minPriceArticle();

    if(minPtr != nullptr)
    {
        std::cout<<"minPrice article: "<<minPtr->name <<" , "<<minPtr->price<<std::endl;
    }

    Article* sortedArticles = myShop.sortedArticles();
    int size = myShop.getSize();
    if(sortedArticles != nullptr)
    {
        for(int i =0 ; i <size ; ++i)
        {
            std::cout<<sortedArticles[i].name<<" : "<<sortedArticles[i].price<<std::endl;
        }
        delete[] sortedArticles;
    }


    return 0;
}