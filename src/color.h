#ifndef COLOR_H_
#define COLOR_H_

using namespace std;

class Color {
        private:
                unsigned char red;
                unsigned char green;
                unsigned char blue;
                unsigned long hex;

        public:
            Color() : red(0), green(0), blue(0), hex(0) {};
            Color(const char* hexString);
            Color(const char* hexString, const char* format);

            unsigned char getRed();
            void setRed(unsigned char r);
            unsigned char getGreen();
            void setGreen(unsigned char g);
            unsigned char getBlue();
            void setBlue(unsigned char b);
            unsigned long getHex();
};

#endif
