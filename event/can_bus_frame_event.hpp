#ifndef A320_CORE_CAN_BUS_FRAME_EVENT_H
#define A320_CORE_CAN_BUS_FRAME_EVENT_H

#include "frames/frame.hpp"

class CanBusFrameEvent 
{
public:
    explicit CanBusFrameEvent() = default;
    virtual ~CanBusFrameEvent() = default;

    virtual void frameReceived(const Frame &frame) = 0;
};

#endif