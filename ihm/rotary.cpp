#include "rotary.hpp"

const uint8_t Rotary::m_tableState[6][4] = {
  // R_START (00)
  {R_START_M,            R_CW_BEGIN,     R_CCW_BEGIN,  R_START},
  // R_CCW_BEGIN
  {R_START_M | DIR_CCW, R_START,        R_CCW_BEGIN,  R_START},
  // R_CW_BEGIN
  {R_START_M | DIR_CW,  R_CW_BEGIN,     R_START,      R_START},
  // R_START_M (11)
  {R_START_M,            R_CCW_BEGIN_M,  R_CW_BEGIN_M, R_START},
  // R_CW_BEGIN_M
  {R_START_M,            R_START_M,      R_CW_BEGIN_M, R_START | DIR_CW},
  // R_CCW_BEGIN_M
  {R_START_M,            R_CCW_BEGIN_M,  R_START_M,    R_START | DIR_CCW},
};

Rotary::Rotary(InputInterface *pInputA, InputInterface *pInputB)
{
    m_pInputA = pInputA;
    m_pInputB = pInputB;
    m_pEvent = nullptr;
    m_bLastState = R_START;
    m_nCountEvent = 0;
}

Rotary::Rotary(InputInterface *pInputA, InputInterface *pInputB, RotaryEvent *pEvent)
{
    m_pInputA = pInputA;
    m_pInputB = pInputB;
    m_pEvent = pEvent;
    m_bLastState = R_START;
    m_nCountEvent = 0;
}

bool Rotary::loop()
{   
    // Grab state of input pins.
    uint8_t nValueA = m_pInputA->read() ? 0x1 : 0x0;
    uint8_t nValueB = m_pInputB->read() ? 0x1 : 0x0;

    uint8_t nRotaryPinsValue = (nValueA << 1) | nValueB;
    // Determine new state from the pins and state table.
    m_bLastState = m_tableState[m_bLastState & 0xf][nRotaryPinsValue];
    // Return emit bits, ie the generated event.
    uint8_t nCurrentState = m_bLastState & 0x30;

    if(m_pEvent != nullptr) 
    {
        if(nCurrentState == DIR_CW) 
        {
            m_nCountEvent++;

            if(m_nCountEvent > 1) 
            {
                m_nCountEvent = 0;
                m_pEvent->onMove(RotaryEvent::e_direction::INCR);
                return true;
            }
        } else if(nCurrentState == DIR_CCW) 
        {
            m_nCountEvent++;
            
            if(m_nCountEvent > 1) 
            {
                m_nCountEvent = 0;
                m_pEvent->onMove(RotaryEvent::e_direction::DECR);
                return true;
            }
        }
    }

    return false;
}