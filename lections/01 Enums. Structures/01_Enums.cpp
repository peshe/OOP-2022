/*
Object - Oriented Programming 2022 @ FMI
Lecture #01, sample code
*/

#include <iostream>

int main_01()
{
    int shirtColour = 1;    // the white colour is coded as 1
    int hatColour = 2;      // the gray colour is coded as 2

    return 0;
}

// use constants instead of the magical numbers
const int COLOUR_WHITE = 1;
const int COLOUR_GRAY = 2;

int main_02()
{
    int shirtColour = COLOUR_WHITE;
    int hatColour = COLOUR_GRAY;

    return 0;
}

// if we have to choose from a predefine set of colours
typedef int colour;

int main_03()
{
    colour shirtColour = COLOUR_WHITE;
    colour hatColour = COLOUR_GRAY;

    std::cout << shirtColour << std::endl;

    // does 8 represent a valid colour?
    colour red = 8;

    // which exactly are the allowed colours?

    return 0;
}

// enumeration, 
// improves readability, the related constants are close to each other

// when the constant values start at 0
// how can we iterated through the constants 
// so that the intruduction of new constants to the enum
// not to break the code? we want to minimize the changes!

enum Colour
{
    UNKNOWN = -1,
    BLACK,
    WHITE,
    GRAY, 
    RED,
    COLOUR_COUNT
}; // be careful with these! they are mandatory!

void print(Colour colour)
{
    std::cout << colour << ' ';

    // when a value of the enum type is not listed in the switch statement, 
    // there is a compiler warning
    switch (colour)
    {
        case BLACK: 
            std::cout << "Black" << std::endl;
            break;
        case WHITE: 
            std::cout << "White" << std::endl;
            break;
        case GRAY:
            std::cout << "Gray" << std::endl;
            break;
        case RED:
            std::cout << "Red" << std::endl;

        default: 
            std::cout << "Unknown" << std::endl;
            break;
    }
}

// the constant values can be used as indices in an array
const char* colourNames[COLOUR_COUNT] = { "black", "white", "gray", "red" };

// how to iterate through the predefined colours
void printAllColours()
{
    for (int colour = UNKNOWN + 1; colour < COLOUR_COUNT; ++colour)
    {
        // an implicit conversion is required
        //print((Colour) colour);

        std::cout << colourNames[colour] << ' ';
    }
}

int main()
{
    // how to define a variable of type Colour?
    Colour shirtColour = WHITE;

    //shirtColour = PINK;     // PINK is not defined. It is not listed as a Colour (enum Colour).
    
    //shirtColour = 0;
    shirtColour = (Colour)0;

    shirtColour = (Colour)8;    // syntactically valid, however... what is the meaning?

    // input and output?
    //std::cin >> shirtColour;    // for a user-defined type the input operation is not defined
    
    // the value is implicitly converted to int
    std::cout << shirtColour << std::endl;

    // what is we what to print out the corresponding text?
    shirtColour = BLACK;
    print(shirtColour);

    // the operators == and != are predefined
    if (shirtColour == BLACK)
    {
        std::cout << "The shirt is black!" << std::endl;
    }

    printAllColours();

    return 0;
}

