#pragma once

class Word
{
private:
    char* symbols;

public:
    void set_symbols(const char* symbols);
    const char* get_symbols() const;

    Word();
    Word(const char* word);
    ~Word();

    char find_Ith(int i);
    void add_symbol(char added_symbol);
    bool is_lex_bigger(const Word& other);
    bool is_lex_smaller(const Word& other);
};