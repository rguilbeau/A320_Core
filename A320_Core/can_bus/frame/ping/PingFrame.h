#ifndef A320_CORE_PING_FRAME_H
#define A320_CORE_PING_FRAME_H

#include "Arduino.h"
#include "A320_Core/can_bus/Frame.h"

class PingFrame {

    public:
        static const unsigned int ID = 0x010;
};

#endif