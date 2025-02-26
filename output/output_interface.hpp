#ifndef A320_CORE_OUTPUT_INTERAFCE_H
#define A320_CORE_OUTPUT_INTERAFCE_H

#include "Arduino.h"

class OutputInterface 
{

public:
    explicit OutputInterface() = default;
    virtual ~OutputInterface() = default;

    virtual void write(const bool &bIsOn) = 0;
};


#endif