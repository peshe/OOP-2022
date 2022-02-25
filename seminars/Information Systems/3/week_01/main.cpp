#include <iostream>
#include <string>

using namespace std;

struct Book {
    char name[64];
    char authorName[64];
    int ISBN;
    char genre[64];
    double price;

    // void createBook(char* _name, char* _authorName, int _ISBN, char* _genre, double _price) {
    //     name = _name;
    //     authorName = _authorName;
    //     ISBN = _ISBN;
    //     genre = _genre;
    //     price = _price;
    // }

    void enterBook() {
        cin.ignore();
        cout << "Enter name: ";
        cin.getline(name, 64);
        cout << "Enter author: ";
        cin.getline(authorName, 64);
        cout << "Enter genre: ";
        cin.getline(genre, 64);
        cout << "Enter ISBN: ";
        cin >> ISBN;
        cout << "Enter price: ";
        cin >> price;
    }

    void print() {
        cout << name << endl;
        cout << authorName << endl;
        cout << ISBN << endl;
        cout << genre << endl;
        cout << price << endl;
    }    
};

const int BOOK_CAPACITY = 1000;
struct BookStore {
    int count;
    Book books[BOOK_CAPACITY];
};

void initializeBookstore(BookStore& store) {
    cout << "Book count: ";
    cin >> store.count;

    for (int i = 0; i < store.count; i++) {
        Book b;
        b.enterBook();
        store.books[i] = b;
    }
}

void getAllBooks(BookStore& store) {
    for (int i = 0; i < store.count; i++) {
        store.books[i].print();
        cout << endl;
    }
}

void getAllBooksByGenre(BookStore& store, const char* genre) {
    for (int i = 0; i < store.count; i++) {
        if (genre == store.books[i].genre) {
            cout << "Genre found: ";
            store.books[i].print();
        }
    }
}

void getAllBooksByAuthorName(BookStore& store, const char* authorName) {
    for (int i = 0; i < store.count; i++) {
        if (authorName == store.books[i].authorName) {
            cout << "Author name found: ";
            store.books[i].print();
        }
    }
}

// ------------------------------------------------

enum Season {
    Winter,
    Spring,
    Summer,
    Autumn
};

// -----------------------------------

const int NAME_SIZE = 128;
const int DESCRIPTION_SIZE = 512;

enum Brand {
    VW, 
    Audi,
    BMW,
    Mercedes,
    Seat
};

enum Engine {
    V8,
    V10,
    V12
};

enum Fuel {
    Gasoline,
    Diesel,
    LPG
};

struct Car {
    int km;
    double avgFuelBurn;
    char name[NAME_SIZE], description[DESCRIPTION_SIZE];
    Brand brand;
    Engine engine;
    Fuel fuel;

    void enterCar() {
        cout << "Enter car:";
        cin.ignore();
        cout << "Enter name:";
        cin.getline(name, NAME_SIZE);
        cout << "Enter description";
        cin.getline(description, DESCRIPTION_SIZE);
        cout << "Enter km:";
        cin >> km; cout << endl;
        cout << "Enter average fuel burn";
        cin >> avgFuelBurn; cout << endl;
    }

    // конструктор с параметри
    Car(int _km, double _avgFuelBurn, const char* _name = "Volvo", const char* _description = "The best car") {
        km = _km;
        avgFuelBurn = _avgFuelBurn;
    }

    void getFuel() {
        switch(fuel) {
            case Gasoline: {
                cout << "Na benzin sme" << endl;
                break;
            } 
            case Diesel: {
                cout << "Na dizel sme" << endl;
                break;
            }
            case LPG: {
                cout << "Na gaz sme" << endl;
                break;
            }
        }
    }
};

int main() {
    // BookStore store1;
    // initializeBookstore(store1);
    // getAllBooks(store1);

    Season s = Winter;
    cout << s << endl;

    Car* myCar = new Car(120, 7.8);
    
    Car myCar1(150, 7.8);
    Car myCar2(99, 7.8);
    Car myCar3(200, 7.8);
}