#ifndef A320_CORE_BRIGHTNESS_PANEL_FRAME_H
#define A320_CORE_BRIGHTNESS_PANEL_FRAME_H

#include "Arduino.h"
#include "A320_Core/can_bus/Frame.h"

class BrightnessPanelFrame {

    public:
        static const unsigned int ID = 0x020;

        BrightnessPanelFrame();

        void decode(Frame *frame);
        
        unsigned char glareshieldPanel;
        unsigned char overheadPanel;
        unsigned char pedestalPanel;
        unsigned char indicators;
        unsigned char buttons;
};

#endif