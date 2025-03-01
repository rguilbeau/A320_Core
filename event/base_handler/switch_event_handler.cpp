#include "switch_event_handler.hpp"

SwitchEventHandler::SwitchEventHandler(CanBus *pCanBus, const e_event &event, const uint8_t &nValueOn, const uint8_t &nValueOff)
{
    m_pCanBus = pCanBus;
    
    m_event = event;
    m_nValueOn = nValueOn;
    m_nValueOff = nValueOff;
}

void SwitchEventHandler::onChange(const bool &bIsOn)
{
    FrameEvent e(m_event, bIsOn ? m_nValueOn : m_nValueOff);
    m_pCanBus->send(e);
}

void SwitchEventHandler::onPing(const bool &bIsOn)
{
    FrameEvent e(m_event, bIsOn ? m_nValueOn : m_nValueOff);
    m_pCanBus->send(e);
}