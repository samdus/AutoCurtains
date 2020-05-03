#include "display.hpp"

void Display::init(){
    begin(16,2);
    backlight();
}

void Display::printTime(unsigned short hour, unsigned short min){
    char buffer [5];
    sprintf (buffer, "%02d:%02d", hour, min);
    print(buffer);
}

void Display::printTime(unsigned short hour, unsigned short min, unsigned short sec){
    char buffer [8];
    sprintf (buffer, "%02d:%02d:%02d", hour, min, sec);
    print(buffer);
}