#ifndef A320_CAN_BUS_H
#define A320_CAN_BUS_H

#include "Arduino.h"
#include "mcp2515.h"
#include "core/can_bus/Frame.h"
#include "core/event/CanBusFrameEvent.h"

class CanBus {

public:
    CanBus(uint8_t cs, CanBusFrameEvent *event);
    void begin();
    void send(Frame *frame);
    void loop();

private:
    CanBusFrameEvent *_event;
    MCP2515 *_mcp2515;
    can_frame *_can_frame;
    
};

#endif