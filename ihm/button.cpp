#include "button.hpp"

Button::Button(InputInterface *pInput)
{
    m_pInput = pInput;
    m_pEvent = nullptr;
    m_bLastState = false;
}

Button::Button(InputInterface *pInput, ButtonEvent *pEvent)
{
    m_pInput = pInput;
    m_pEvent = pEvent;
    m_bLastState = false;
}

bool Button::loop()
{
    bool bValue = m_pInput->read();
    
    if(bValue && !m_bLastState && m_pEvent != nullptr) 
    {
        m_bLastState = bValue;
        m_pEvent->onClick();
        return true;
    } 
    else 
    {
        m_bLastState = bValue;
        return false;
    }
}