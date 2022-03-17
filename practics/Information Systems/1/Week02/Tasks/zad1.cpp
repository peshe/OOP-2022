#include<iostream>
#include<fstream>
#include<string>

void createFile(const char* fileName)
{
    std::ofstream out(fileName);
    if(out.is_open())
    {
        out<<"successfully created"<<'\n';
        out.close();
    }

}

std::string firstLetters(const char* fileName)
{
    std::ifstream in(fileName);
    std::string line;
    std::string result;
    if(in.is_open())
    {
        while(std::getline(in , line))
        {
            result += line[0];
        }

        in.close();
    }
    return result;
}

void printFile(const char* fileName)
{
    std::ifstream in(fileName);
    if(in.is_open())
    {
        std::string line;
        while(std::getline(in , line))
        {
            std::cout<<line<<std::endl;
        }
        in.close();
    }
}

bool renameFile(const char* oldFileName , const char* newFileName)
{
    if(std::rename(oldFileName , newFileName) == 0)
    {
        return true;
    }
    return false;

}

bool removeFile(const char* fileName)
{
    if(std::remove(fileName) == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    

    return 0;
}