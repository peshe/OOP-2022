#include <iostream>

#include "Word.hpp"

int main()
{
    Word w1("SU");
    Word w2("FMI");

    std::cout << w2.find_Ith(1) << std::endl;

    std::cout << w1.get_symbols() << std::endl;
    
    w2.add_symbol('!');
    std::cout << w2.get_symbols() << std::endl;

    std::cout << std::boolalpha << w1.is_lex_bigger(w2) << std::endl;
    std::cout << w1.is_lex_smaller(w2) << std::endl;
}