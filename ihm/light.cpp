#include "light.hpp"

Light::Light(OutputInterface *pOutput)
{
    m_pOutput = pOutput;
    m_bState = false;
}

void Light::on(const bool &bIsOn)
{
    m_bState = bIsOn;
    m_pOutput->write(m_bState);
}

void Light::force(const bool &bIsOn)
{
    m_pOutput->write(bIsOn);
}

void Light::disableForce()
{
    m_pOutput->write(m_bState);
}