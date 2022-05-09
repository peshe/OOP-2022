#include <iostream>
#include <cstring>
#include <fstream>

class Date {
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
    Date waranty; // default constructor
    int power;

    void copy(const ElectricDevice& other) {
        // either this, or call setters which do the same
        this->model = new char[strlen(other.model) + 1];
        strcpy(this->model, other.model);

        this->brand = new char[strlen(other.brand) + 1];
        strcpy(this->brand, other.brand);

        this->waranty = other.waranty;
        this->power = other.power;
    }

    void erase() {
        delete[] model;
        delete[] brand;
    }
public:
    ElectricDevice() {
        this->model = nullptr;
        this->brand = nullptr;
        this->power = 0;
    }

    ElectricDevice(const char* model, const char* brand, int power) {
        this->setModel(model);
        this->setBrand(brand);
        this->power = power;
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

    void setBrand(const char* brand) {
        this->brand = new char[strlen(brand) + 1]; // for terminal 0
        strcpy(this->brand, brand);
    }

    void setModel(const char* model) {
        this->model = new char[strlen(model) + 1]; 
        strcpy(this->model, model);
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

    // for power
    int power_capacity;
    const int MAX_POWER_CAPACITY = 1000; 

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
    ElectricInstallation() {
        this->size = 0;
        this->capacity = 8;
        this->devices = new ElectricDevice[this->capacity];

        this->power_capacity = 0;
    };

    void add_device(const ElectricDevice& device) {
        const int power = device.getPower();
        if (this->power_capacity + power > MAX_POWER_CAPACITY) {
            std::cout << "Cannot add " << device.getModel() << ", exceeding maximum capacity" << std::endl;
            return;
        }

        if (this->size >= this->capacity) {
            this->resize();
        }

        this->power_capacity += power;
        this->devices[this->size++] = device;
    }   

    void remove_device(const char* model) {
        // TODO pract
    }

    void print_devices() const {
        std::cout << "Current capacity of installation: " << this->power_capacity << std::endl;
        std::cout << "MAXIMUM CAPACITY: " << this->MAX_POWER_CAPACITY << std::endl;

        for (int i = 0; i < this->size; i++) {
            devices[i].print();
        }
    }

    void writeDevices(const char* path) {
        std::ofstream out(path, std::ios::binary);

        if (!out) {
            std::cout << "Cannot open file" << std::endl;
            return;
        }

        for (int i = 0; i < this->size; i++) {
            out.write((char*) &this->devices[i], sizeof(ElectricDevice));
        }

        out.close();
    }

    void readDevices(const char* path) {
        std::ifstream in(path, std::ios::binary);

        if (!in.is_open() && !in) {
            std::cout << "Cannot read from file" << std::endl;
            return;
        }

        for (int i = 0; i < this->size; i++) {
            in.read((char*) &this->devices[i], sizeof(ElectricDevice));
            this->devices[i].print();
        }

        in.close();
    }
};

// void readInstallation()
// void writeInstallation()   pract

int main() {
    ElectricInstallation installation;

    ElectricDevice device1("G5-6317ygudhaE", "GORENGE", 120);
    ElectricDevice device2("X564eg-2222", "MARKA", 100);

    installation.add_device(device1);
    installation.add_device(device2);

    // installation.writeInstallation();

    installation.writeDevices("devices.bin");
    installation.readDevices("devices.bin");
}