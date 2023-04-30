#ifndef A320_CORE_BRIGHTNESS_SEVEN_SEGMENTS_FRAME_H
#define A320_CORE_BRIGHTNESS_SEVEN_SEGMENTS_FRAME_H

#include "Arduino.h"
#include "A320_Core/can_bus/Frame.h"

class BrightnessSevenSegmentsFrame {

    public:
        static const unsigned int ID = 0x030;

        BrightnessSevenSegmentsFrame();

        void decode(Frame *frame);

        bool isTestLight;
        unsigned char fcu;
        unsigned char altimeters;
        unsigned char bateries;
        unsigned char radio;
};

#endif