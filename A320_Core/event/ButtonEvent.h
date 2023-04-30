#ifndef A320_CORE_BUTTON_EVENT_H
#define A320_CORE_BUTTON_EVENT_H

#include "Arduino.h"

class ButtonEvent {

    public:
        virtual void onClick() = 0;

};

#endif