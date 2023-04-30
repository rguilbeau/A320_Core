#ifndef A320_CORE_GLARESHIELD_INDICATORS_FRAME_H
#define A320_CORE_GLARESHIELD_INDICATORS_FRAME_H

#include "Arduino.h"
#include "A320_Core/can_bus/Frame.h"

class GlareshieldIndicatorsFrame {

    public:
        static const unsigned int ID = 0x021;

        GlareshieldIndicatorsFrame();

        void decode(Frame *frame);

        bool ap1;
        bool ap2;
        bool athr;
        bool loc;
        bool exped;
        bool appr;
};

#endif