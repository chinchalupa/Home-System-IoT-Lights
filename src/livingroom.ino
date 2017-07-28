// This #include statement was automatically added by the Particle IDE.
#include <SparkJson.h>
#include <neopixel.h>

#include <stdlib.h>

#define PIXEL_COUNT 60
#define PIXEL_PIN D5
#define PIXEL_TYPE WS2812B2

#define MAX_COLOR_VALUE 255

#define UDP_BUFFER_SIZE 512

SYSTEM_THREAD(ENABLED);
// SYSTEM_MODE(SEMI_AUTOMATIC);



class Color {
    public:
        Color(String hexString) {
            hex = strtol(hexString, nullptr, 16);
            blue = (byte)(hex & 0xff);
            green = (byte)((hex >> 8) & 0xff);
            red = (byte)((hex >> 16) & 0xff);
        }
        void setRed(byte r) {
            red = r;
        }
        void setBlue(byte b) {
            blue = b;
        }
        void setGreen(byte g) {
            green = g;
        }
        byte getRed() {
            return red;
        }
        byte getBlue() {
            return blue;
        }
        byte getGreen() {
            return green;
        }
        unsigned int getHex() {
            return hex;
        }
        void parseHex(String hexString) {
            hex = strtol(hexString, nullptr, 16);
            blue = hex & 0xFF;
            green = (hex >> 8) & 0xFF;
            red = (hex >> 16) & 0xFF;
        }
    private:
        unsigned int hex;
        byte red;
        byte green;
        byte blue;
};


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
        
        setAllColor(udpBuffer);
    }
    
    strip.show();
}


void setLEDs(int led, Color color) {
    strip.setPixelColor(led, color.getGreen(), color.getBlue(), color.getRed());
}


int setAllColor(String command) {
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(udpBuffer);
    
    if(!root.success()) {
        Particle.publish("Parsing failed");
    }
    
    const char* c = root["color"];
    unsigned int startLed = root["startLed"];
    unsigned int endLed = root["endLed"];

    Color color = Color(c);
    
    for(int i = startLed; i < endLed; i++) {
        setLEDs(i, color);
    }
    
    return 1;
}

