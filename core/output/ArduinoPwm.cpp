#include "ArduinoPwm.h"

ArduinoPwm::ArduinoPwm(uint8_t pin)
{
    _pin = pin;
    pinMode(pin, OUTPUT);
    analogWrite(_pin, 0);
}

void ArduinoPwm::write(unsigned char value)
{
    analogWrite(_pin, value);
}