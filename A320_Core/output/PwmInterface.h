#ifndef A320_CORE_PWM_INTERAFCE_H
#define A320_CORE_PWM_INTERAFCE_H

#include "Arduino.h"

class PwmInterface {

public:

    virtual void write(unsigned char value) = 0;
};

#endif