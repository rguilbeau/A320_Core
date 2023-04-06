#ifndef FCU_BRIGHTNESS_FRAME
#define FCU_BRIGHTNESS_FRAME

#include "Arduino.h"
#include "core/can_bus/Frame.h"

class BrightnessFrame {

    public:

        BrightnessFrame();

        void decode(Frame *frame);
        
        short fcuDisplayContrast;
};

#endif