#include <iostream>
#include <fstream>

struct Point
{
    int x;
    int y;
};

void enterPoint(Point& pt)
{
    std::cout << "x: ";
    std::cin >> pt.x;
    std::cout << "y: ";
    std::cin >> pt.y;
}

void writePointInFile(const char* fileName, Point& pt)
{
    std::ofstream out(fileName, std::ios::binary);
    if (!out.is_open())
    {
        std::cout << "error while opening" << std::endl;
        return;
    }

    out.write((const char*)&pt, sizeof(Point));
    out.close();

}

void readPointFromFile(const char* fileName)
{
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open())
    {
        std::cout << "error while opening" << std::endl;
        return;
    }

    Point pt;
    in.read((char*)&pt, sizeof(Point));
    in.close();
    std::cout << "x: " << pt.x << " y: " << pt.y << std::endl;

}


int main()
{
    Point pt;
    enterPoint(pt);
    writePointInFile("text.txt", pt);
    readPointFromFile("text.txt");

    return 0;
}