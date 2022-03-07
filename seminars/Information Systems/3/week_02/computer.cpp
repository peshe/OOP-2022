#include <iostream>

// вместо using namespace std
using std::cin;
using std::cout;
using std::endl;

enum Videocards
{
    invalidVideocard,
    GigabyteGeForceRTX2070Super,
    PowerColorRadeonRX5700XT,
    EVGAGeForceRTX2070SuperXC,
    ASRockAMDRadeonRX5600XT,
    AMDRadeonRX5704GB,
    NvidiaGeForceRTX2080Super,
    NvidiaGeForceRTX2060Super,
    NvidiaGeForceRTX2070Super,
    AMDRadeonRX5700XT
};
enum Procesors
{
    invalidProcesor,
    AMDRyzen53600,
    AMDRyzen73700X,
    AMDRyzen93900X,
    IntelCorei99900K,
    IntelCorei712700K,
    IntelCorei511400F,
    AMDRyzenTR3960X,
    unknown,
};
enum Cores
{
    doesntExist,
    twoCore,
    fourCore,
    eightCore,
};
enum TypeOfMemory
{
    invalidTypeM,
    SSD,
    HDD
};
enum TypeOfComputer
{
    invalidTypeC,
    laptop,
    desktopComputer
};

struct computer
{
    int bateryCapacity;
    double screensize;
    char brand[32];
    Videocards videocard;
    Procesors procesor;
    Cores coress;
    TypeOfMemory memoryType;
    TypeOfComputer typeComp;

    void create()
    {
        cout << "Enter batery capacity " << endl;
        cin >> bateryCapacity;
        cout << "Enter screensize" << endl;
        cin >> screensize;
        cin.ignore();
        cout << "Enter name of brand" << endl;
        cin.getline(brand, 32);
        int userinput;
        do
        {
            cout << "Enter vidiocard" << endl;
            cout << " 1-Gigabyte GeForce RTX2070Super" << endl;
            cout << " 2-PowerColorRadeonRX5700XT" << endl;
            cout << " 3-EVGAGeForceRTX2070SuperXC " << endl;
            cout << " 5-ASRockAMDRadeonRX5600XT " << endl;
            cout << " 6-AMDRadeonRX5704GB" << endl;
            cout << " 7-NvidiaGeForceRTX2080Super" << endl;
            cout << " 8-NvidiaGeForceRTX2060Super" << endl;
            cout << " 9-NvidiaGeForceRTX2070Super" << endl;
            cout << " 10-AMDRadeonRX5700XT" << endl;
            cin >> userinput;
        } while (getVideocard(userinput) == 0);
        videocard = getVideocard(userinput);

        do
        {
            cout << "Enter procesor" << endl;
            cout << " 1-AMDRyzen53600" << endl;
            cout << " 2-AMDRyzen93900X" << endl;
            cout << " 3-IntelCorei99900K " << endl;
            cout << " 4-IntelCorei99900K " << endl;
            cout << " 6-IntelCorei511400F " << endl;
            cout << " 7- AMDRyzenTR3960X" << endl;
            cin >> userinput;
        } while (getProcesor(userinput) == 0);
        procesor = getProcesor(userinput);

        do
        {
            cout << "Enter cores" << endl;
            cout << " 1-two cores" << endl;
            cout << " 2-four cores" << endl;
            cout << " 3-eight cores " << endl;
            cin >> userinput;
        } while (getCores(userinput) == 0);
        coress = getCores(userinput);

        do
        {
            cout << "Enter laptop or computer" << endl;
            cout << " 1-laptop" << endl;
            cout << " 2-desktop computer" << endl;
            cin >> userinput;
        } while (getTypeC(userinput) == 0);
        typeComp = getTypeC(userinput);

        do
        {
            cout << "Enter SSD or HDD" << endl;
            cout << " 1-SSD" << endl;
            cout << " 2-HDD" << endl;
            cin >> userinput;
        } while (getTypeM(userinput) == 0);
        memoryType = getTypeM(userinput);
    }

    void print()
    {
        if (typeComp == laptop)
        {
            cout << "Batery capacity : " << bateryCapacity << endl;
        }
        cout << "Screen size : " << screensize << endl;
        cout << "Brand : " << brand << endl;
        cout << "Videocard : ";
        switch (videocard)
        {
        case 1:
            cout << "GigabyteGeForceRTX2070Super";
            break;
        case 2:
            cout << "PowerColorRadeonRX5700XT";
            break;
        case 3:
            cout << "EVGAGeForceRTX2070SuperXC";
            break;
        case 4:
            cout << "ASRockAMDRadeonRX5600XT";
            break;
        case 5:
            cout << "AMDRadeonRX5704GB";
            break;
        case 6:
            cout << "NvidiaGeForceRTX2080Super";
            break;
        case 7:
            cout << "NvidiaGeForceRTX2060Super";
            break;
        case 8:
            cout << "NvidiaGeForceRTX2070Super";
            break;
        case 9:
            cout << "AMDRadeonRX5700XT";
            break;
        }
        cout << endl
             << "Procesor : ";
        switch (procesor)
        {
        case 1:
            cout << "AMDRyzen53600";
            break;
        case 2:
            cout << "AMDRyzen73700X";
            break;
        case 3:
            cout << "AMDRyzen93900X";
            break;
        case 4:
            cout << "IntelCorei99900K";
            break;
        case 5:
            cout << "IntelCorei712700K";
            break;
        case 6:
            cout << "IntelCorei511400F";
            break;
        case 7:
            cout << "AMDRyzenTR3960X";
            break;
        }
        cout << endl
             << "Coress : ";
        switch (coress)
        {
        case 1:
            cout << "twoCore";
            break;
        case 2:
            cout << "fourCore";
            break;
        case 3:
            cout << "eightCore";
            break;
        }

        cout << endl
             << "Memory type : ";
        {
            switch (memoryType)
            {
            case 1:
                cout << "SSD";
                break;
            case 2:
                cout << "HDD";
                break;
            }
        }
        cout << endl
             << "Type of computer : ";

        switch (typeComp)
        {
        case 1:
            cout << "laptop";
            break;
        case 2:
            cout << "desktopComputer";
            break;
        }
    }

    Videocards getVideocard(int userInput)
    {
        switch (userInput)
        {
        case 1:
            return GigabyteGeForceRTX2070Super;
        case 2:
            return PowerColorRadeonRX5700XT;
        case 3:
            return EVGAGeForceRTX2070SuperXC;
        case 4:
            return ASRockAMDRadeonRX5600XT;
        case 5:
            return AMDRadeonRX5704GB;
        case 6:
            return NvidiaGeForceRTX2080Super;
        case 7:
            return NvidiaGeForceRTX2060Super;
        case 8:
            return NvidiaGeForceRTX2070Super;
        case 9:
            return AMDRadeonRX5700XT;
        default:
            return invalidVideocard;
        }
    }

    Procesors getProcesor(int userInput)
    {
        switch (userInput)
        {
        case 1:
            return AMDRyzen53600;
        case 2:
            return AMDRyzen73700X;
        case 3:
            return AMDRyzen93900X;
        case 4:
            return IntelCorei99900K;
        case 5:
            return IntelCorei511400F;
        case 6:
            return AMDRyzenTR3960X;
        default:
            return invalidProcesor;
        }
    }

    Cores getCores(int userInput)
    {
        switch (userInput)
        {
        case 1:
            return twoCore;
        case 2:
            return fourCore;
        case 3:
            return eightCore;
        default:
            return doesntExist;
        }
    }

    TypeOfComputer getTypeC(int userInput)
    {
        switch (userInput)
        {
        case 1:
            return laptop;
        case 2:
            return desktopComputer;
        default:
            return invalidTypeC;
        }
    }

    TypeOfMemory getTypeM(int userInput)
    {
        switch (userInput)
        {
        case 1:
            return SSD;
        case 2:
            return HDD;
        default:
            return invalidTypeM;
        }
    }
};

int main() {
    TypeOfComputer comp = laptop;
    cout << comp << endl;

    computer c;
    c.create();
}