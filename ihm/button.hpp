#ifndef A320_CORE_BUTTON_H
#define A320_CORE_BUTTON_H

#include "Arduino.h"
#include "ihm/ihm_interface.hpp"
#include "input/input_interface.hpp"
#include "event/button_event.hpp"

class Button : public IhmInterface 
{
public:
    explicit Button(InputInterface *pInput);
    explicit Button(InputInterface *pInput, ButtonEvent *pEvent);
    virtual ~Button() = default;

    bool loop() override;

private:
    InputInterface *m_pInput;
    ButtonEvent *m_pEvent;
    bool m_bLastState;
};

#endif