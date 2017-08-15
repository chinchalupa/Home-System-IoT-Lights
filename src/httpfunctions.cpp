#include "httpfunctions.h"
#include "color.h"

HttpFunctions::HttpFunctions(Strip s) : strip(s) {}

int HttpFunctions::setAllToColor(String command) {
    Color c = Color(command);
    strip.setPixelColorsInRange(0, 120, c);
    return 0;
}
