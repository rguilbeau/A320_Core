#include "arduino_pwm.hpp"

ArduinoPwm::ArduinoPwm(const uint8_t &nPin)
{
    m_nPin = nPin;

    pinMode(m_nPin, OUTPUT);
    analogWrite(m_nPin, 0);
}

void ArduinoPwm::write(const uint8_t &nValue)
{
    analogWrite(m_nPin, nValue);
}