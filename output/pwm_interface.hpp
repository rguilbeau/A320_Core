#ifndef A320_CORE_PWM_INTERAFCE_H
#define A320_CORE_PWM_INTERAFCE_H

#include "Arduino.h"

class PwmInterface 
{

public:
    explicit PwmInterface() = default;
    virtual ~PwmInterface() = default;

    virtual void write(const uint8_t &nValue) = 0;
    virtual void setPower(const bool &bPower) = 0;
};

#endif