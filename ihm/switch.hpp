#ifndef A320_CORE_SWITCH_H
#define A320_CORE_SWITCH_H

#include "Arduino.h"
#include "input/input_interface.hpp"
#include "ihm/ihm_interface.hpp"
#include "event/switch_event.hpp"
#include "ping/ping.hpp"

class Switch : public IhmInterface 
{
public:
    explicit Switch(InputInterface *pInput, Ping *pPing = nullptr);
    explicit Switch(InputInterface *pInput, SwitchEvent *pEvent, Ping *pPing = nullptr);
    virtual ~Switch() = default;

    bool loop() override;

private:
    InputInterface *m_pInput;
    SwitchEvent *m_pEvent;
    Ping *m_pPing;
    
    bool m_bLastValue;
};

#endif