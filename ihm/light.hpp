#ifndef A320_CORE_LIGHT_H
#define A320_CORE_LIGHT_H

#include "Arduino.h"
#include "output/output_interface.hpp"

class Light 
{

public:
    explicit Light(OutputInterface *pOutput);
    virtual ~Light() = default;
    
    void on(const bool &bIsOn);
    void force(const bool &bIsOn);
    void disableForce();

private:
    OutputInterface *m_pOutput;
    bool m_bState;
};

#endif