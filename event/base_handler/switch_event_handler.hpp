#ifndef FCU_SWITCH_EVENT_HANDLER_H
#define FCU_SWITCH_EVENT_HANDLER_H

#include "Arduino.h"
#include "event/switch_event.hpp"
#include "can_bus/can_bus.hpp"

class SwitchEventHandler : public SwitchEvent 
{
public:
    explicit SwitchEventHandler(CanBus *pCanBus, const e_event &event, const uint8_t &nValueOn = 1, const uint8_t &nValueOff = 0);
    virtual ~SwitchEventHandler() = default;

    void onChange(const bool &bIsOn) override;
    void onPing(const bool &bIsOn) override;

private:
    CanBus *m_pCanBus;
    
    e_event m_event;
    uint8_t m_nValueOn;
    uint8_t m_nValueOff;
};

#endif