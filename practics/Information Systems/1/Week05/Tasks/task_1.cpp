#include <iostream>

class Car {
private:
    char number[256];
    char name[256];
    char model[256];
    char color[256];

public:
    Car() {
        this->number[0] = '\0';
        this->name[0] = '\0';
        this->model[0] = '\0';
        this->color[0] = '\0';
    }

    Car(const char* number, const char* name, const char* model, const char* color) {
        strcpy_s(this->number, number);
        strcpy_s(this->name, name);
        strcpy_s(this->model, model);
        strcpy_s(this->color, color);
    }

    Car(const Car& other) {
        strcpy_s(this->number, other.number);
        strcpy_s(this->name, other.name);
        strcpy_s(this->model, other.model);
        strcpy_s(this->color, other.color);
    }

    const char* getNumber() {
        return this->number;
    }

    const char* getName() {
        return this->name;
    }

    const char* getModel() {
        return this->model;
    }

    const char* getColor() {
        return this->color;
    }

    void setNumber(const char* number) {
        strcpy_s(this->number, number);
    }

    void setName(const char* name) {
        strcpy_s(this->name, name);
    }

    void setModel(const char* model) {
        strcpy_s(this->model, model);
    }

    void setColor(const char* color) {
        strcpy_s(this->color, color);
    }

    bool checkNumberForPalindrom() {
        char number[4];
        unsigned count = 0;
        for (unsigned i = 0; this->number[i] != '\0'; ++i) {
            if (this->number[i] >= '0' && this->number[i] <= '9') {
                number[count++] = this->number[i];
            }
        }

        for (unsigned i = 0; i < count / 2; ++i) {
            if (number[i] != number[count - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Car car1("CA1221BH", "Opel", "Vectra", "Red");

    std::cout << car1.checkNumberForPalindrom() << std::endl;
    return 0;
}