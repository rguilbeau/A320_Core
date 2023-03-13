#ifndef A320_OUTPUT_INTERAFCE_H
#define A320_OUTPUT_INTERAFCE_H

#include "Arduino.h"

class OutputInterface {

public:

    virtual void write(bool on) = 0;

};


#endif