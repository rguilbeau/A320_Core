#ifndef A320_BUTTON_EVENT_H
#define A320_BUTTON_EVENT_H

#include "Arduino.h"

class ButtonEvent {

    public:
        virtual void onClick() = 0;

};

#endif