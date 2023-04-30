#ifndef A320_CORE_CAN_BUS_FRAME_EVENT_H
#define A320_CORE_CAN_BUS_FRAME_EVENT_H

#include "A320_Core/can_bus/Frame.h"

class CanBusFrameEvent {

public:
    virtual void frameReceived(Frame *frame) = 0;
};

#endif