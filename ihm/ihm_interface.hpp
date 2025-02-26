#ifndef A320_CORE_IHM_INTERFACE_H
#define A320_CORE_IHM_INTERFACE_H

#include "Arduino.h"

class IhmInterface 
{

public:
    explicit IhmInterface() = default;
    virtual ~IhmInterface() = default;

    virtual bool loop() = 0;
};

#endif