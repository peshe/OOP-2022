#include <iostream>
#include <cstring>

#include "Word.hpp"

void Word::set_symbols(const char* symbols)
{
    if (symbols == nullptr)
    {
        throw "Invalid word!";
    }
    
    delete[] this->symbols;
    this->symbols = new char[strlen(symbols) + 1];
    strcpy(this->symbols, symbols);
}

const char* Word::get_symbols() const
{
    return this->symbols;
}

Word::Word() 
{
    this->symbols = nullptr;
}

Word::Word(const char* symbols)
{
    this->symbols = new char[strlen(symbols) + 1];
    strcpy(this->symbols, symbols);
}

Word::~Word()
{
    delete[] this->symbols;
}

char Word::find_Ith(int i)
{
    return this->symbols[i];
}

void Word::add_symbol(char added_symbol)
{
    int length = strlen(this->symbols);
    char* new_symbols = new char[length + 2];

    for(int i = 0; i < length; i++)
    {
        new_symbols[i] = this->symbols[i];
    }

    new_symbols[length] = added_symbol;
    new_symbols[length + 1] = '\0';

    if(this->symbols != nullptr)
    {
        delete[] this->symbols;
    }

    this->symbols = new_symbols;
}

bool Word::is_lex_bigger(const Word& other)
{
    return strcmp(this->symbols, other.symbols) < 0;
}

bool Word::is_lex_smaller(const Word& other)
{
    return !this->is_lex_bigger(other);
}