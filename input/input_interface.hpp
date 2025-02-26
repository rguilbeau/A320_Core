#ifndef A320_CORE_INPUT_INTERFACE_H
#define A320_CORE_INPUT_INTERFACE_H

#include "Arduino.h"

class InputInterface
{
public:
    explicit InputInterface() = default;
    virtual ~InputInterface() = default;

    virtual bool read() = 0;
};

#endif