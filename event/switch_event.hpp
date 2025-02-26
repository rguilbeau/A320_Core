#ifndef A320_CORE_SWITCH_EVENT_H
#define A320_CORE_SWITCH_EVENT_H

#include "Arduino.h"

class SwitchEvent 
{

public:
    explicit SwitchEvent() = default;
    virtual ~SwitchEvent() = default;

    virtual void onChange(const bool &bIsOn) = 0;
};

#endif