#include "button_event_handler.hpp"

ButtonEventHandler::ButtonEventHandler(CanBus *pCanBus, const e_event &event)
{
    m_pCanBus = pCanBus;
    m_event = event;
}

void ButtonEventHandler::onClick()
{    
    FrameEvent e(m_event);
    m_pCanBus->send(e);
}