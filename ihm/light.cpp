#include "light.hpp"

Light::Light(OutputInterface *pOutput)
{
    m_pOutput = pOutput;
    m_bState = false;
    m_bIsPowered = false;
    m_bIsTestLight = false;
}

void Light::on(const bool &bIsOn)
{
    m_bState = bIsOn;

    if(!m_bIsPowered)
    {
        m_pOutput->write(false);
    }
    else if(m_bIsTestLight)
    {
        m_pOutput->write(true);
    }
    else
    {
        m_pOutput->write(m_bState);
    }
}

void Light::setTestLight(const bool &bIsTestLight)
{
    m_bIsTestLight = bIsTestLight;
    on(m_bState);
}

void Light::setPower(const bool &bIsPowered)
{
    m_bIsPowered = bIsPowered;
    on(m_bState);
}

