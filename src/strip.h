#include <neopixel.h>
#include "color.h"
#ifndef STRIP_H
#define STRIP_H

class Strip {
    public:
        Strip(int pCount, int dPin, int sType);

        void initialize();
        void diagnoseStrip();
        void setPixelColorsInRange(int startPixel, int endPixel, Color color);

    private:
        int pixelCount;
        int digitalPin;
        int stripType;
        Adafruit_NeoPixel strip;
};
#endif
