#ifndef A320_CORE_OUTPUT_INTERAFCE_H
#define A320_CORE_OUTPUT_INTERAFCE_H

#include "Arduino.h"

class OutputInterface {

public:

    virtual void write(bool on) = 0;

};


#endif