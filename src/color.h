#include <stdlib.h>
#include "application.h"

#ifndef COLOR_H
#define COLOR_H

class Color {
    public:
        Color(char r, char g, char b); 
        Color(String);

        char getRed();
        char getGreen();
        char getBlue();

    private:
        char red;
        char green;
        char blue;
        float alpha;
        char hex[8];
        
};

#endif

