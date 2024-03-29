#include "CanBus.h"

CanBus::CanBus(uint8_t cs, CanBusFrameEvent *event)
{
    _mcp2515 = new MCP2515(cs);
    _event = event;
    _isPing = false;
}

void CanBus::begin()
{
    _mcp2515->reset();
    _mcp2515->setBitrate(CAN_125KBPS, MCP_8MHZ);
    _mcp2515->setNormalMode();
}

void CanBus::begin(const unsigned long *ids, const unsigned short numIds)
{
    _mcp2515->reset();
    _mcp2515->setBitrate(CAN_125KBPS, MCP_8MHZ);

    _mcp2515->setConfigMode();

    _mcp2515->setFilterMask(MCP2515::MASK0, false, 0x7FF);
    _mcp2515->setFilterMask(MCP2515::MASK1, false, 0x7FF);

    for (uint8_t i = 0; i < numIds; i++) {
        _mcp2515->setFilter((MCP2515::RXF)i, false, ids[i]);        
    }

    _mcp2515->setNormalMode();
}

bool CanBus::loop()
{
    bool eventFired = false;
    _isPing = false;

    MCP2515::ERROR error = _mcp2515->readMessage(&_mcp_can_frame);

    if(error != MCP2515::ERROR_OK && error != MCP2515::ERROR_NOMSG) {
        // ERROR_OK        = 0
        // ERROR_FAIL      = 1
        // ERROR_ALLTXBUSY = 2
        // ERROR_FAILINIT  = 3
        // ERROR_FAILTX    = 4
        // ERROR_NOMSG     = 5
    } else if (error == MCP2515::ERROR_OK) {
        Frame frame(_mcp_can_frame.can_id, _mcp_can_frame.can_dlc);

        for(unsigned short i = 0; i < _mcp_can_frame.can_dlc; i++) {
            frame.setData(i, _mcp_can_frame.data[i]);
        }

        if(_event != nullptr) {
            _event->frameReceived(&frame);
            eventFired = true;
        }

        if(frame.getId() == PingFrame::ID) {
            _isPing = true;
        }
    }

    return eventFired;
}

bool CanBus::isPing()
{
    return _isPing;
}

void CanBus::send(Frame *frame)
{
    struct can_frame can_frame;
    can_frame.can_id = frame->getId();
    can_frame.can_dlc = frame->getSize();

    for(unsigned short i = 0; i < frame->getSize(); i++) {
        can_frame.data[i] = frame->getData(i);
    } 

    _mcp2515->sendMessage(&can_frame);
}

void CanBus::sendEvent(unsigned short idEvent, float data, bool isPing)
{
    Frame frame(0x000, 7);
    frame.setData(0, (idEvent >> 8) & 0xFF);
    frame.setData(1, idEvent & 0xFF);

    byte octets[4];
    memcpy(octets, &data, sizeof(data));

    for (int i = 0; i < 4; i++) {
        frame.setData(2 + i, octets[i]);
    }

    if(isPing) {
        frame.setData(6, 0x01);
    } else {
        frame.setData(6, 0x00);
    }
    
    send(&frame);
}