#ifndef A320_CORE_PING_H
#define A320_CORE_PING_H

#include "Arduino.h"

class Ping
{
public:
    explicit Ping(const uint32_t &nInterval);
    virtual ~Ping() = default;

    bool isPing();

private:
    uint32_t m_nInterval;
    unsigned long m_nLastMillis;
};


#endif