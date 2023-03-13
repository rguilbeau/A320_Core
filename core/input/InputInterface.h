#ifndef A320_INPUT_INTERFACE_H
#define A320_INPUT_INTERFACE_H

#include "Arduino.h"

class InputInterface
{
    public:
        virtual bool read() = 0;
};

#endif