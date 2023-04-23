#ifndef FCU_CAN_BUS_FRAME_EVENT_H
#define FCU_CAN_BUS_FRAME_EVENT_H

#include "core/can_bus/Frame.h"

class CanBusFrameEvent {

public:
    virtual void frameReceived(Frame *frame) = 0;
};

#endif