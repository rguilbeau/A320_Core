#ifndef FCU_BRIGHTNESS_FRAME
#define FCU_BRIGHTNESS_FRAME

#include "Arduino.h"
#include "A320_Corecan_bus/Frame.h"

class BrightnessFrame {

    public:
        static const unsigned int ID = 0x001;

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