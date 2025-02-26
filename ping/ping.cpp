#include "ping.hpp"

Ping::Ping(const uint32_t &nInterval)
{
    m_nInterval = nInterval;
}

bool Ping::isPing()
{
    unsigned long nCurrenMillis = millis();

    if((m_nLastMillis + m_nInterval) > nCurrenMillis)
    {
        m_nLastMillis = nCurrenMillis;
        return true;
    }
    else
    {
        return false;
    }
}