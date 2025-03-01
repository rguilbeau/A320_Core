#ifndef A320_CORE_ROTARY_H
#define A320_CORE_ROTARY_H

#include "Arduino.h"
#include "input/input_interface.hpp"
#include "ihm/ihm_interface.hpp"
#include "event/rotary_event.hpp"
#include "lib/RotaryEncoder.h"

class Rotary : public IhmInterface 
{

public:
    explicit Rotary(InputInterface *pInputA, InputInterface *pInputB);
    explicit Rotary(InputInterface *pInputA, InputInterface *pInputB, RotaryEvent *pEvent);
    virtual ~Rotary() = default;

    bool loop() override;

private:
    RotaryEncoder m_rotaryEncoder;
    InputInterface *m_pInputA;
    InputInterface *m_pInputB;
    RotaryEvent *m_pEvent;
    uint8_t m_bLastState;
    uint16_t m_nCountEvent;

    int m_currentPos = 0;
};


#endif