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
    void setTestLight(const bool &bIsTestLight);
    void setPower(const bool &bIsPowered);

private:
    OutputInterface *m_pOutput;
    bool m_bState;
    bool m_bIsTestLight;
    bool m_bIsPowered;
};

#endif