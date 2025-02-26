#include "switch.hpp"

Switch::Switch(InputInterface *pInput, Ping *pPing)
{
    m_pInput = pInput;
    m_bLastValue = false;
    m_pEvent = nullptr;
    m_pPing = pPing;
}

Switch::Switch(InputInterface *pInput, SwitchEvent *pEvent, Ping *pPing)
{
    m_pInput = pInput;
    m_bLastValue = false;
    m_pEvent = pEvent;
    m_pPing = pPing;
}

bool Switch::loop()
{
    if(m_pEvent != nullptr)
    {
        bool bValue = m_pInput->read();
        
        if(m_bLastValue != bValue) 
        {
            m_bLastValue = bValue;
            m_pEvent->onChange(m_bLastValue);

            return true;
        }

        if(m_pPing != nullptr)
        {
            if(m_pPing->isPing())
            {
                m_pEvent->onPing(bValue);
            }
        }
    }

    return false;
}