#include <iostream>

enum RGBColor {
    None,
    Red,
    Green,
    Blue
};

struct Color {
    RGBColor set[3]; // 0 - values for red, 1 - values for green, 2 - values for blue.
    char name[256];
};

// array with colors - values can be red, green, blue or none
// [None, None, None] - black - 0, 0, 0 - 0
// [Red, None, None] - red - 1, 0, 0 - 1
// [None, Green, None] - green - 0, 2, 0 - 2
// [None, None, Blue] - blue - 0, 0, 3 - 3
// [Red, Green, None] - yellow - 1, 2, 0 - 3
// [Red, None, Blue] - purple - 1, 0, 3 - 4
// [None, Green, Blue] - cyan - 0, 2, 3 - 5

bool checkColorArray(const Color& color) {
    if (color.set[0] != RGBColor::None && color.set[0] != RGBColor::Red) {
        return false;
    }
    
    if (color.set[1] != RGBColor::None && color.set[1] != RGBColor::Green) {
        return false;
    }

    if (color.set[2] != RGBColor::None && color.set[2] != RGBColor::Blue) {
        return false;
    }
    return true;
}

void setColorName(Color& color) {
    if (!checkColorArray(color)) {
        std::cout << "Not correct values array" << std::endl;
        return;
    }

    unsigned values = 0;
    for (unsigned i = 0; i < 3; ++i) {
        values += color.set[i];
    }

    switch (values)
    {
        case 0: strcpy_s(color.name, "black"); break;
        case 1: strcpy_s(color.name, "red"); break;
        case 2: strcpy_s(color.name, "green"); break;
        case 3: if (color.set[0] == RGBColor::None && color.set[1] == RGBColor::None) {
                strcpy_s(color.name, "blue");
            }
            else {
                strcpy_s(color.name, "yellow");
            }
            break;
        case 4: strcpy_s(color.name, "purple"); break;
        case 5: strcpy_s(color.name, "cyan"); break;
        default: strcpy_s(color.name, "black"); break;
    }
}

int main()
{
    Color color = { {None, None, Blue} };
    setColorName(color);
    std::cout << color.name << std::endl;

    return 0;
}