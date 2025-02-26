#ifndef A320_CORE_ROTARY_H
#define A320_CORE_ROTARY_H

#include "Arduino.h"
#include "input/input_interface.hpp"
#include "ihm/ihm_interface.hpp"
#include "event/rotary_event.hpp"

// Values returned by 'process'
// No complete step yet.
#define DIR_NONE 0x0
// Clockwise step.
#define DIR_CW 0x10
// Counter-clockwise step.
#define DIR_CCW 0x20

#define R_START 0x0

#define R_CCW_BEGIN 0x1
#define R_CW_BEGIN 0x2
#define R_START_M 0x3
#define R_CW_BEGIN_M 0x4
#define R_CCW_BEGIN_M 0x5

class Rotary : public IhmInterface 
{

public:
    explicit Rotary(InputInterface *pInputA, InputInterface *pInputB);
    explicit Rotary(InputInterface *pInputA, InputInterface *pInputB, RotaryEvent *pEvent);
    virtual ~Rotary() = default;

    bool loop() override;

private:
    InputInterface *m_pInputA;
    InputInterface *m_pInputB;
    RotaryEvent *m_pEvent;
    uint8_t m_bLastState;
    uint16_t m_nCountEvent;
    static const uint8_t m_tableState[6][4]; 
};


#endif