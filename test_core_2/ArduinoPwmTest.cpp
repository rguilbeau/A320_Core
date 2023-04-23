#include "ArduinoPwmTest.h"

ArduinoPwmTest::ArduinoPwmTest(uint8_t pin)
{
    _pin = pin;
    pinMode(pin, OUTPUT);
    analogWrite(_pin, 0);
}

void ArduinoPwmTest::write(unsigned char value)
{
    analogWrite(_pin, value);
}