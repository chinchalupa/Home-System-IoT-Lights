// This #include statement was automatically added by the Particle IDE.
#include <SparkJson.h>
#include <neopixel.h>

#include "color.h"
#include "strip.h"

#include <stdlib.h>

#define PIXEL_COUNT 120 
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2812 

#define MAX_COLOR_VALUE 255
#define UDP_BUFFER_SIZE 512

SYSTEM_THREAD(ENABLED);

Strip s = Strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

UDP udp;
unsigned int localPort = 8888;

// Particle function definitions
int setAllToColor(String command) {
    Color color = Color(command);
    
    s.setPixelColorsInRange(0, PIXEL_COUNT, color);
    return 0;
}

void setup() {

    s.initialize();

    s.setPixelColorsInRange(0, 120, Color("ff00ff"));

    s.setPixelColorsInRange(0, 60, Color(0, 0, 255));

    waitUntil(WiFi.ready);
    Particle.function("AllColor", setAllToColor); 
}

void loop() {
    
}


