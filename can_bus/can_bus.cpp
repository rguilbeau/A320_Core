#include "can_bus.hpp"

CanBus::CanBus(const uint8_t &nCs, CanBusFrameEvent *pEvent)
{
    m_pMcp2515 = new MCP2515(nCs);
    m_pEvent = pEvent;
}

CanBus::~CanBus()
{
    delete m_pMcp2515;
    m_pMcp2515 = 0;
}

void CanBus::setCallback(CanBusFrameEvent *pEvent)
{
    m_pEvent = pEvent;
}

void CanBus::begin()
{
    m_pMcp2515->reset();
    m_pMcp2515->setBitrate(CAN_1000KBPS, MCP_8MHZ);
    m_pMcp2515->setNormalMode();
}

void CanBus::begin(const uint32_t *ids, const uint16_t &nNumIds)
{
    m_pMcp2515->reset();
    m_pMcp2515->setBitrate(CAN_1000KBPS, MCP_8MHZ);

    m_pMcp2515->setConfigMode();

    m_pMcp2515->setFilterMask(MCP2515::MASK0, false, 0x7FF);
    m_pMcp2515->setFilterMask(MCP2515::MASK1, false, 0x7FF);

    for (uint16_t i = 0; i < nNumIds; i++) 
    {
        m_pMcp2515->setFilter((MCP2515::RXF)i, false, ids[i]);        
    }

    m_pMcp2515->setNormalMode();
}

bool CanBus::loop()
{
    bool bEventFired = false;

    can_frame mcpCanFrame;
   
    while(m_pMcp2515->readMessage(&mcpCanFrame) == MCP2515::ERROR_OK)
    {
        e_frameId frameId = static_cast<e_frameId>(mcpCanFrame.can_id);
                
        Frame frame(frameId, mcpCanFrame.can_dlc, mcpCanFrame.data);

        if(m_pEvent != nullptr) 
        {
            m_pEvent->frameReceived(frame);
            bEventFired = true;
        }
    }

    return bEventFired;
}

void CanBus::send(const Frame &frame)
{
    struct can_frame canFrame;
    canFrame.can_id = frame.getId();
    canFrame.can_dlc = frame.getSize();

    const uint8_t *data = frame.getData();

    for(unsigned short i = 0; i < frame.getSize(); i++) 
    {
        canFrame.data[i] = data[i];
    } 
    m_pMcp2515->sendMessage(&canFrame);
}