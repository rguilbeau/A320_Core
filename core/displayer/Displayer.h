#ifndef A320_DISPLAYER_H
#define A320_DISPLAYER_H

#include "Arduino.h"
#include <Adafruit_SSD1306.h>
#include "core/displayer/fonts/Nimbus_Sans_L_Bold_16.h"
#include "core/displayer/fonts/DSEG7_Classic_Mini_Bold_25.h"

class Displayer
{

    public:
        void begin(uint8_t address);

        void setContrast(short value);
        void displayNone();
        
    protected:
        Displayer(Adafruit_SSD1306 *screen, short indexDisplay);
        Displayer(Adafruit_SSD1306 *screen);
        Adafruit_SSD1306 *_screen;

        short _indexDisplay;

        String leftPad(int value, int size);
        void selectScreen();
        
    private:
        static short  _selectedScreen;
};

#endif