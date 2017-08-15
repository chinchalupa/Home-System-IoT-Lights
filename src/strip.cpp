#include "strip.h"

Strip::Strip(int pCount, int dPin, int sType) : pixelCount(pCount), digitalPin(dPin), stripType(sType), strip(pCount, dPin, sType) {}

void Strip::initialize() {

    strip.begin();
    strip.show();
}

void Strip::diagnoseStrip() {
    for (int i = 0; i < pixelCount; i++) {
        strip.setPixelColor(i, 0, 0, 255);
    }
    strip.show();
}

void Strip::setPixelColorsInRange(int startPixel, int endPixel, Color color) {
    for (int i = startPixel; i < endPixel; i++) {
        strip.setPixelColor(i, color.getRed(), color.getGreen(), color.getBlue());
    }
    strip.show();
}


