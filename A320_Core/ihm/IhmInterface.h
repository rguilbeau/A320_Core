#ifndef A320_CORE_IHM_INTERFACE_H
#define A320_CORE_IHM_INTERFACE_H

#include "Arduino.h"

class IhmInterface {

public:

    virtual bool loop() = 0;
    virtual void ping() = 0;

};

#endif