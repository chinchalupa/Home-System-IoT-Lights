#include "color.h"
#include <stdlib.h>


Color::Color(const char* hexString) {
    hex = strtoul(hexString, nullptr, 16);

    green = (hex >> 16) & 0xff;
    red = (hex >> 8) & 0xff;
    blue = hex & 0xff;
}
Color::Color(const char* hexString, const char* format) {
           char hexShifted[] = {hexString[5], hexString[2], hexString[1], hexString[4], hexString[3], hexString[0]};
            
    hex = strtoul(hexShifted, nullptr, 16);
    green = (hex >> 16) & 0xff;
    red = (hex >> 8) & 0xff;
    blue = hex & 0xff;
}
void Color::setRed(unsigned char r) {
    red = r;
}
void Color::setBlue(unsigned char b) {
    blue = b;
}
void Color::setGreen(unsigned char g) {
    green = g;
}
unsigned char Color::getRed() {
    return red;
}
unsigned char Color::getBlue() {
    return blue;
}
unsigned char Color::getGreen() {
    return green;
}
unsigned long Color::getHex() {
    return hex;
}
