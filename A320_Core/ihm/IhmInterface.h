#ifndef A320_IHM_INTERFACE_H
#define A320_IHM_INTERFACE_H

#include "Arduino.h"

class IhmInterface {

public:

    virtual bool loop() = 0;

};

#endif