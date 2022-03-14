#include<iostream>
#include<fstream>
#include <cstring>

using namespace std;

int main() {
   std::ofstream out("test.bin", std::ios::binary);

   int number1 = 12345;
   std::cout << &number1 << std::endl;
   out.write((char*) &number1, sizeof(number1));
   // out.write((char*) &number2, sizeof(number2));
   out.close();

   int readNum;
   std::ifstream in("test.bin", std::ios::binary);

   in.read((char*) &readNum, sizeof(readNum));

   std::cout << "The value of the number AFTER reading is " << readNum << endl;

   in.close();

   // NOTE: different number of bytes saved here
   // std::ofstream file("test");
   // int num = 12345;
   // file << num;      // << transforms everything to CHAR
   // file.close();   
}