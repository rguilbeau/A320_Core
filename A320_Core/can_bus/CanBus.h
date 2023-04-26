#ifndef A320_CAN_BUS_H
#define A320_CAN_BUS_H

#include "Arduino.h"
#include "Adafruit_BusIO_Register.h"
#include "mcp2515.h"
#include "A320_Core/can_bus/Frame.h"
#include "A320_Core/event/CanBusFrameEvent.h"

class CanBus {

public:
    CanBus(uint8_t cs);

    void setEventHandler(CanBusFrameEvent *event);
    void begin();
    void begin(const unsigned long *ids, const unsigned short numIds);

    void send(Frame *frame);
    bool loop();
    void sendEvent(unsigned short idEvent, float data);

private:
    CanBusFrameEvent *_event;
    MCP2515 *_mcp2515;
    struct can_frame _mcp_can_frame;
};

#endif