#ifndef A320_CORE_BUTTON_EVENT_H
#define A320_CORE_BUTTON_EVENT_H

#include "Arduino.h"

class ButtonEvent 
{
public:
    explicit ButtonEvent() = default;
    virtual ~ButtonEvent() = default;
    
    virtual void onClick() = 0;
};

#endif