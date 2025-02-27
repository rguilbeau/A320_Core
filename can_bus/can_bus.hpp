#ifndef A320_CORE_CAN_BUS_H
#define A320_CORE_CAN_BUS_H

#include "Arduino.h"
#include "mcp2515.h"
#include "event/can_bus_frame_event.hpp"
#include "frames/frame.hpp"
#include "frames/frame_event.hpp"

class CanBus 
{
public:
    explicit CanBus(const uint8_t &nCs, CanBusFrameEvent *pEvent = nullptr);
    virtual ~CanBus();

    void setCallback(CanBusFrameEvent *pEvent);

    void begin();
    void begin(const uint32_t *ids, const uint16_t &nNumIds);

    void send(const Frame &frame);
    bool loop();

private:
    CanBusFrameEvent *m_pEvent;
    MCP2515 *m_pMcp2515;

    can_frame m_mcpCanFrame;
};

#endif