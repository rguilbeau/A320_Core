#ifndef A320_CORE_SWITCH_EVENT_H
#define A320_CORE_SWITCH_EVENT_H

#include "Arduino.h"

class SwitchEvent {

public:
    virtual void onChange(bool isOn) = 0;
};

#endif