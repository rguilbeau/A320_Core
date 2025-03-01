#include "rotary.hpp"

Rotary::Rotary(InputInterface *pInputA, InputInterface *pInputB): 
    m_rotaryEncoder{pInputA, pInputB, RotaryEncoder::LatchMode::FOUR0}
{
    m_pEvent = nullptr;
}

Rotary::Rotary(InputInterface *pInputA, InputInterface *pInputB, RotaryEvent *pEvent):
    m_rotaryEncoder{pInputA, pInputB, RotaryEncoder::LatchMode::FOUR0}
{
    m_pEvent = pEvent;
}

bool Rotary::loop()
{   
    m_rotaryEncoder.tick();
    int nNewPos = m_rotaryEncoder.getPosition();

    if (m_currentPos != nNewPos) 
    {
        RotaryEncoder::Direction direction = m_rotaryEncoder.getDirection();

        if(direction == RotaryEncoder::Direction::COUNTERCLOCKWISE)
        {
            m_pEvent->onMove(RotaryEvent::e_direction::INCR);
            return true;
        }
        else if(direction == RotaryEncoder::Direction::CLOCKWISE)
        {
            m_pEvent->onMove(RotaryEvent::e_direction::DECR);
            return true;
        }

        m_currentPos = nNewPos;
    }

    return false;
}