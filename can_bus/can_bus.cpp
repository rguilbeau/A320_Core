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
    m_pMcp2515->setBitrate(CAN_125KBPS, MCP_8MHZ);
    m_pMcp2515->setNormalMode();
}

void CanBus::begin(const uint32_t *ids, const uint16_t &nNumIds)
{
    m_pMcp2515->reset();
    m_pMcp2515->setBitrate(CAN_125KBPS, MCP_8MHZ);

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

    MCP2515::ERROR error = m_pMcp2515->readMessage(&m_mcpCanFrame);

    if(error != MCP2515::ERROR_OK && error != MCP2515::ERROR_NOMSG) 
    {
        // ERROR_OK        = 0
        // ERROR_FAIL      = 1
        // ERROR_ALLTXBUSY = 2
        // ERROR_FAILINIT  = 3
        // ERROR_FAILTX    = 4
        // ERROR_NOMSG     = 5
    } 
    else if (error == MCP2515::ERROR_OK) 
    {
        Frame frame(m_mcpCanFrame.can_id, m_mcpCanFrame.can_dlc, m_mcpCanFrame.data);

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