#include <iostream>
#include <cstring>
#include <fstream>

class Date {
private:
    int day, month, year;
public:
    Date() : day(1), month(1), year(1970) {}

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    Date& operator=(const Date& other) {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
    }
};

class ElectricDevice {
private:
    char* model;
    char* brand;
    Date date;
    int power;

    void copy(const ElectricDevice& other) {
        this->model = new char[strlen(other.model) + 1];
        strcpy(this->model, other.model);

        this->brand = new char[strlen(other.brand) + 1];
        strcpy(this->brand, other.brand);

        this->date = other.date;
        this->power = other.power;
    }

    void erase() {
        delete[] model;
        delete[] brand;
    }
public:
    ElectricDevice() {
        this->model = new char[64];
        this->brand = new char[64];

        strcpy(this->model, "Default model");
        strcpy(this->brand, "Default brand");
        this->date = Date();
        this->power = 0;
    }

    ElectricDevice(const ElectricDevice& other) {
        this->copy(other);
    }

    ElectricDevice& operator=(const ElectricDevice& other) {
        if (this != &other) {
            this->erase();
            this->copy(other);
        }

        return *this;
    }

    ~ElectricDevice() {
        this->erase();
    }

    int getPower() const {
        return this->power;
    }

    const char* getModel() const {
        return this->model;
    }

    void print() const {
        std::cout << "Model: " << this->model << std::endl;
        std::cout << "Brand: " << this->brand << std::endl;
        std::cout << "Power: " << this->power << std::endl;
    }
};

class ElectricInstallation {
private:
    ElectricDevice* devices;
    int size;
    int capacity;

    int power_capacity;
    int MAX_POWER_CAPACITY;

    void resize() {
        this->capacity *= 2;

        ElectricDevice* bigger = new ElectricDevice[this->capacity];

        for (int i = 0; i < this->size; i++) {
            bigger[i] = this->devices[i];
        }

        this->erase();
        this->devices = bigger;
    }

    void erase() {
        delete[] this->devices;
    }
public:
    ElectricInstallation() : MAX_POWER_CAPACITY(10000), power_capacity(0) {
        this->size = 0;
        this->capacity = 8;
        this->devices = new ElectricDevice[this->capacity];
    }

    void add_device(const ElectricDevice& device) {
        // power exceed verification
        const int power = device.getPower();
        if (this->power_capacity + power > MAX_POWER_CAPACITY) {
            std::cout << "Cannot add this device, exceeding maximum capacity!" << std::endl;
            return;
        }

        if (this->size > this->capacity) {
            std::cout << "resizing..." << std::endl;
            this->resize();
        }

        power_capacity += power;

        this->devices[this->size++] = device;
    }

    void remove_device(char* model) {
        const ElectricDevice* device = nullptr;
        
        for (int i = 0; i < this->size; i++) {
            if (strcmp(this->devices[i].getModel(), model) == 0) {
                device = new ElectricDevice(this->devices[i]); // copy constructor :)
            }
        }
    }

    const ElectricDevice& operator[](int index) {
        if (index > this->size - 1) {
            throw std::out_of_range("Index you passed is greater than installation size");
        }

        const ElectricDevice* device = nullptr;
        
        for (int i = 0; i < this->size; i++) {
            if (i == index) {
                device = new ElectricDevice(this->devices[i]); // copy constructor :)
            }
        }

        return *device;
    }

    void print_devices() const {
        std::cout << "Current capacity of installation: " << this->power_capacity << std::endl;
        std::cout << "Maximum capacity: " << this->MAX_POWER_CAPACITY << std::endl;

        for (int i = 0; i < this->size; i++) {
            devices[i].print();
        }
    }

    void saveToBinary(const char* path) const {
        std::ofstream out(path, std::ios::binary);

        if (!out) {
            std::cout << "Cannot open file" << std::endl;
            return;
        }

        for (int i = 0; i < 3; i++) {
            out.write((char*) &this->devices[i], sizeof(ElectricDevice));
        }

        out.close();
    }

    void readFromBinary(const char* path) const {
        std::ifstream in(path, std::ios::binary);

        if (!in.is_open() && !in) {
            std::cout << "Cannot read from file" << std::endl;
            return;
        }

        for (int i = 0; i < 3; i++) {
            in.read((char*) &this->devices[i], sizeof(ElectricDevice));
            this->devices[i].print();
        }

        in.close();
    }
};

int main() {
    ElectricInstallation* installation = new ElectricInstallation();

    ElectricDevice device_1;
    ElectricDevice device_2;

    installation->add_device(device_1);
    installation->add_device(device_2);

    // installation->print_devices();

    installation->saveToBinary("installation.bin");
    installation->readFromBinary("installation.bin");

    ElectricInstallation test;
    test.add_device(device_1);
    ElectricDevice operatorTest = test[0];
    std::cout << "Returned device from operator: "<< std::endl;
    operatorTest.print();
}