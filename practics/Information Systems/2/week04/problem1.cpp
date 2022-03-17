#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int COMPANY_NAME_LEN = 25;

struct jobApplication {

    char companyName[COMPANY_NAME_LEN];
    size_t teamMembersCount;
    size_t yearlyPaidLeave;
    size_t salary;
};

void printJobListing(jobApplication& obj) {
    
    std::cout << "\nJob offer by: " << obj.companyName << '\n'
        << "Team members: " << obj.teamMembersCount << '\n'
        << "Yearly paid leave: " << obj.yearlyPaidLeave << '\n'
        << "Project salary: " << obj.salary << "\n";
}

void inputJobApplication(jobApplication& obj) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    std::cin.getline(obj.companyName, COMPANY_NAME_LEN, '\n');

    std::cin >> obj.teamMembersCount
            >> obj.yearlyPaidLeave
            >> obj.salary;

}

void saveToBinFile(const char* filePath, const jobApplication& obj) {

    std::ofstream saveFile(filePath, std::ios::binary & std::ios::app); // ios::app, allows writing only in the end of the file, 
                                                     // we don't want to mess up old data by rewriting it

    if (!saveFile.is_open()) {
        std::cout << "Error! Couldn't open file " << filePath << '\n';
        return;
    }

    saveFile.write((const char*)&obj, sizeof(obj));
    saveFile.close();
}

void saveToStream(std::ofstream& os, const jobApplication& obj) {
    os.write((const char*)&obj, sizeof(obj));
}

void loadFromBinFile(const char* filePath, jobApplication& obj) {
    
    std::ifstream loadFile(filePath, std::ios::binary);

    if (!loadFile.is_open()) {
        std::cout << "Error! Couldn't open file " << filePath << '\n';
        return;
    }

    loadFile.read((char*)&obj, sizeof(obj));
    loadFile.close();
}

// similar to function above, but here we have already opened a stream from outside this method;
// using the above function, a new file would always be created and we'll always read the first jobApplication in the binary file
void loadFromStream(std::istream& is, jobApplication& obj) {

    is.read((char*)&obj, sizeof(obj));
}

void inputJobOffers(size_t count) {

    std::ofstream saveFile("data.bin", ios::app & ios::app);

    for (int i = 0; i < count; ++i) {
        jobApplication listing;
        
        inputJobApplication(listing);
        saveToStream(saveFile, listing);
    }
    saveFile.close();
}

void filterOffers(const char* filePath, long long minSalary) {

    ifstream dataFile(filePath, ios::binary);

    if (!dataFile.is_open())  {
        std::cout << "Error! Couldn't open file " << filePath << '\n';
        return;
    }

    while (true) {

        jobApplication obj;
        loadFromStream(dataFile, obj);

        if (!dataFile) { break; }

        if (obj.salary >= minSalary) {

            printJobListing(obj);
        }

        
    }
    dataFile.close();
}

bool existOffer(const char* filePath, const char* name) {
    ifstream dataFile(filePath, ios::binary);

    if (!dataFile.is_open())  {
        std::cout << "Error! Couldn't open file " << filePath << '\n';
        return 0;
    }

    while (dataFile) {
        jobApplication obj;
        
        loadFromStream(dataFile, obj);

        if (!strcmp(obj.companyName, name)) {

            return true;
        }
    }
    dataFile.close();
    return false;
}

void run(const char* filePath) {
    char ch;
    

    while (ch != 'q') {
        std::cin >> ch;

        switch(ch) {
            case 'a' : {

                inputJobOffers(1);
            }
            break;

            case 'i' : {
                filterOffers(filePath, 0);
            }
            break;

            case 's' : {
                std::cin.clear();
                std::cin.ignore(1000, '\n');

                char name[COMPANY_NAME_LEN];
                cin.getline(name, COMPANY_NAME_LEN, '\n');

                std::cout << '\n' << boolalpha << existOffer(filePath, name);
                std::cout << '\n';
            }
            break;

            case 'f' : {
                size_t salary;
                std::cin >> salary;

                filterOffers(filePath, salary);
            }
            break;

            case 'q': {
                std::cout << "\n\ngoodbye!";
            }

            break;
        }
    }
}

int main() {

    run("data.bin");
}