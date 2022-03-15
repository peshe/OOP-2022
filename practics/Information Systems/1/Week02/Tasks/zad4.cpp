#include<iostream>
#include<fstream>
#include<string>

void removeEmptyLines(const char* fileName )
{
    std::ifstream in(fileName);
   
    std::ofstream out("temp.txt");
   
    if(!in.is_open() || !out.is_open() )
    {
        std::cout<<"Can't open file"<<std::endl;
        return;

    }
    std::string line;

    while(std::getline(in , line))
    {
        if(line != "")
        {
            out<<line<<'\n';
        }
        
    }
    
    in.close();
    out.close();

    if(std::remove(fileName) == 0)
    {   
        std::cout<<"successfully removed"<<std::endl;
        if(std::rename("temp.txt" , fileName) == 0)
        {
            std::cout<<"successfully renamed"<<std::endl;
        }

    }

}

int main()
{
  
   
    return 0;
}