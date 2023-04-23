#include "Rotary.h"

const unsigned char Rotary::_tableState[6][4] = {
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

Rotary::Rotary(InputInterface *inputA, InputInterface *inputB)
{
    _inputA = inputA;
    _inputB = inputB;
    _event = nullptr;
    _lastState = R_START;
    _countEvent = 0;
}

Rotary::Rotary(InputInterface *inputA, InputInterface *inputB, RotaryEvent *event)
{
    _inputA = inputA;
    _inputB = inputB;
    _event = event;
    _lastState = R_START;
    _countEvent = 0;
}

bool Rotary::loop()
{   
    // Grab state of input pins.
    unsigned char valueA = _inputA->read() ? 0x1 : 0x0;
    unsigned char valueB = _inputB->read() ? 0x1 : 0x0;

    unsigned char rotaryPinsValue = (valueA << 1) | valueB;
    // Determine new state from the pins and state table.
    _lastState = _tableState[_lastState & 0xf][rotaryPinsValue];
    // Return emit bits, ie the generated event.
    unsigned char currentState = _lastState & 0x30;

    if(_event != nullptr) {
        if(currentState == DIR_CW) {
            _countEvent++;

            if(_countEvent > 1) {
                _countEvent = 0;
                _event->onMove(RotaryEventDirection::INCR);
                return true;
            }
        } else if(currentState == DIR_CCW) {
            _countEvent++;
            
            if(_countEvent > 1) {
                _countEvent = 0;
                _event->onMove(RotaryEventDirection::DECR);
                return true;
            }
        }
    }

    return false;
}