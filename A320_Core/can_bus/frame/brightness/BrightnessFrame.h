#ifndef A320_CORE_BRIGHTNESS_FRAME_H
#define A320_CORE_BRIGHTNESS_FRAME_H

#include "Arduino.h"
#include "A320_Core/can_bus/Frame.h"

class BrightnessFrame {

    public:
        static const unsigned int ID = 0x020;

        BrightnessFrame();

        void decode(Frame *frame);
        
        bool testLight;
        unsigned char segmentsScreens;
        unsigned char glareshieldPanel;
        unsigned char overheadPanel;
        unsigned char pedestalPanel;
        unsigned char indicators;
        unsigned char buttons;
};

#endif