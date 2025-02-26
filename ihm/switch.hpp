#ifndef A320_CORE_SWITCH_H
#define A320_CORE_SWITCH_H

#include "Arduino.h"
#include "input/input_interface.hpp"
#include "ihm/ihm_interface.hpp"
#include "event/switch_event.hpp"

class Switch : public IhmInterface 
{
public:
    explicit Switch(InputInterface *pInput);
    explicit Switch(InputInterface *pInput, SwitchEvent *pEvent);
    virtual ~Switch() = default;

    bool loop() override;

private:
    InputInterface *m_pInput;
    SwitchEvent *m_pEvent;
    bool m_bLastValue;
};

#endif