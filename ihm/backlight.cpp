#include "backlight.hpp"
    
Backlight::Backlight(PwmInterface *pOutput)
{
    m_pOutput = pOutput;
}

void Backlight::set(uint8_t nValue)
{
    m_nValue = nValue;
    
    if(m_bIsPowered)
    {
        m_pOutput->write(m_nValue);
    }
    else
    {
        m_pOutput->write(0);
    }
}

void Backlight::setPower(bool const &nPowered)
{
    m_bIsPowered = nPowered;
    set(m_nValue);
}