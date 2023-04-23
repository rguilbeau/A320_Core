#ifndef A320_ARDUINO_PWM_H
#define A320_ARDUINO_PWM_H

#include "Arduino.h"
#include "core/output/PwmInterface.h"

class ArduinoPwm : public PwmInterface {

public:
    ArduinoPwm(uint8_t pin);

    void write(unsigned char value) override;

private:
    uint8_t _pin;
};

#endif