#ifndef FCU_GLARESHIELD_INDICATORS_FRAME
#define FCU_GLARESHIELD_INDICATORS_FRAME

#include "Arduino.h"
#include "A320_Core/can_bus/Frame.h"

class GlareshieldIndicatorsFrame {

    public:
        static const unsigned int ID = 0x102;

        GlareshieldIndicatorsFrame();

        void decode(Frame *frame);

        bool ap1;
        bool ap2;
        bool athr;
        bool loc;
        bool exped;
        bool appr;
        bool isPowerOn;
};

#endif