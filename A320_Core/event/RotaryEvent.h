#ifndef A320_CORE_ROTARY_EVENT_H
#define A320_CORE_ROTARY_EVENT_H

#include "Arduino.h"

enum RotaryEventDirection {INCR, DECR, NONE};

class RotaryEvent {

    public:
        virtual void onMove(RotaryEventDirection direction) = 0;

};

#endif