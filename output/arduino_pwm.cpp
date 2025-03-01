#include "arduino_pwm.hpp"

ArduinoPwm::ArduinoPwm(const uint8_t &nPin)
{
    m_nPin = nPin;

    pinMode(m_nPin, OUTPUT);
    analogWrite(m_nPin, m_nValue);
}

void ArduinoPwm::write(const uint8_t &nValue)
{
    m_nValue = nValue;
    
    if(m_bIsPowered)
    {
        analogWrite(m_nPin, nValue);
    }
    else
    {
        analogWrite(m_nPin, 0);
    }
}

void ArduinoPwm::setPower(const bool &bPower)
{
    m_bIsPowered = bPower;
    write(m_nValue);
}