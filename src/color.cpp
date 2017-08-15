#include "color.h"

Color::Color(char r, char g, char b) : red(r), green(g), blue(b) {}

Color::Color(String s) {
    long colorHex = strtol(s, nullptr, 16);
    red = colorHex >> 16 & 0xff;
    green = colorHex >> 8 & 0xff;
    blue = colorHex & 0xff;
}

char Color::getRed() {
    return red;
}

char Color::getGreen() {
    return green;
}

char Color::getBlue() {
    return blue;
};


