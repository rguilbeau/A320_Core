#ifndef A320_ARDUINO_PWM_TEST_H
#define A320_ARDUINO_PWM_TEST_H

#include "Arduino.h"

class ArduinoPwmTest {

public:
    ArduinoPwmTest(uint8_t pin);

    void write(unsigned char value);

private:
    uint8_t _pin;
};

#endif