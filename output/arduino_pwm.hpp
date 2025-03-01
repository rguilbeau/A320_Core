#ifndef A320_CORE_ARDUINO_PWM_H
#define A320_CORE_ARDUINO_PWM_H

#include "Arduino.h"
#include "output/pwm_interface.hpp"

class ArduinoPwm : public PwmInterface 
{

public:
    explicit ArduinoPwm(const uint8_t &nPin);
    virtual ~ArduinoPwm() = default;

    void write(const uint8_t &nValue) override;
    void setPower(const bool &bPower) override;

private:
    uint8_t m_nPin;
    uint8_t m_nValue = 0;
    bool m_bIsPowered = false;
};

#endif