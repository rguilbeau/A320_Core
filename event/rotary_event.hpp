#ifndef A320_CORE_ROTARY_EVENT_H
#define A320_CORE_ROTARY_EVENT_H

#include "Arduino.h"

class RotaryEvent 
{

public:
    enum e_direction 
    {
        INCR, 
        DECR, 
        NONE
    };

    explicit RotaryEvent() = default;
    virtual ~RotaryEvent() = default;

    virtual void onMove(const e_direction &direction) = 0;
};

#endif