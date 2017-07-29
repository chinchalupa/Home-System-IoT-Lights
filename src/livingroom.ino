// This #include statement was automatically added by the Particle IDE.
#include <SparkJson.h>
#include <neopixel.h>
#include "color.h"

#include <stdlib.h>

#define PIXEL_COUNT 60
#define PIXEL_PIN D5
#define PIXEL_TYPE SK6812RGBW 

#define MAX_COLOR_VALUE 255

#define UDP_BUFFER_SIZE 512

SYSTEM_THREAD(ENABLED);
// SYSTEM_MODE(SEMI_AUTOMATIC);




Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


void setLEDs(int, Color);


int setAllColor(String command);

char udpBuffer[UDP_BUFFER_SIZE + 1];


unsigned int localPort = 8888;
UDP udp;


void setup() {
    strip.begin();
    strip.show();
      
    waitUntil(WiFi.ready);
    udp.begin(localPort);

    Particle.function("color", setAllColor);
}

void loop() {
    if (udp.parsePacket() > 0) {
        int count = 0;
        
        while (udp.available()) {
            udpBuffer[count] = udp.read();
            count++;
        }
        //Particle.publish("signal", "signal received");
 
        setAllColor(udpBuffer);
    }
    
    strip.show();
}


void setLEDs(int led, Color color) {
    strip.setPixelColor(led, color.getRed(), color.getGreen(), color.getBlue());
}


int setAllColor(String command) {
    //Particle.publish("Stuff", "Got Here");
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(udpBuffer);
    
    if(!root.success()) {
        Particle.publish("Parsing failed");
    }
    
    const char* c = root["color"];
    unsigned int startLed = root["startLed"];
    unsigned int endLed = root["endLed"];

    Color color = Color(c, "R");
   //Particle.publish("red", color.getRed());    
    //Particle.publish("green", color.getGreen());

    for(unsigned int i = startLed; i < endLed; i++) {
        setLEDs(i, color);
    }
    
    return 1;
}
