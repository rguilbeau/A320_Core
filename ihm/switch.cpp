#include "switch.hpp"

Switch::Switch(InputInterface *pInput)
{
    m_pInput = pInput;
    m_bLastValue = false;
    m_pEvent = nullptr;
}

Switch::Switch(InputInterface *pInput, SwitchEvent *pEvent)
{
    m_pInput = pInput;
    m_bLastValue = false;
    m_pEvent = pEvent;
}

bool Switch::loop()
{
    bool bValue = m_pInput->read();
    
    if(m_bLastValue != bValue && m_pEvent != nullptr) 
    {
        m_bLastValue = bValue;
        m_pEvent->onChange(m_bLastValue);

        return true;
    }

    return false;
}