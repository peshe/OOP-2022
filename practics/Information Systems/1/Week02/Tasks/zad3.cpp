#include<iostream>
#include<fstream>
#include<string>

void combineFiles(const char* firstFileName , const char* secondFileName)
{
    std::ifstream inFirstFile(firstFileName);
    std::ifstream inSecondFile(secondFileName);
    std::ofstream newFile("combined.txt");
   
    if(!inFirstFile.is_open() || !inSecondFile.is_open() || !newFile.is_open())
    {
        std::cout<<"Can't open file"<<std::endl;
        return;

    }
    std::string line;
    while(std::getline(inFirstFile , line))
    {
        newFile<<line<<'\n';
    }
    while(std::getline(inSecondFile , line))
    {
        newFile<<line<<'\n';
    }
    inFirstFile.close();
    inSecondFile.close();
    newFile.close();

}

int main()
{
   
    return 0;
}