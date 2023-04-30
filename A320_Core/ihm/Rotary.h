#ifndef A320_CORE_ROTARY_H
#define A320_CORE_ROTARY_H

#include "Arduino.h"
#include "A320_Core/input/InputInterface.h"
#include "A320_Core/ihm/IhmInterface.h"
#include "A320_Core/event/RotaryEvent.h"

/*#define R_CW_FINAL 0x1
#define R_CW_BEGIN 0x2
#define R_CW_NEXT 0x3
#define R_CCW_BEGIN 0x4
#define R_CCW_FINAL 0x5
#define R_CCW_NEXT 0x6
#define R_START 0x0
#define R_DIR_CW 0x10
#define R_DIR_CCW 0x20*/

// Values returned by 'process'
// No complete step yet.
#define DIR_NONE 0x0
// Clockwise step.
#define DIR_CW 0x10
// Counter-clockwise step.
#define DIR_CCW 0x20

#define R_START 0x0

#define R_CCW_BEGIN 0x1
#define R_CW_BEGIN 0x2
#define R_START_M 0x3
#define R_CW_BEGIN_M 0x4
#define R_CCW_BEGIN_M 0x5

class Rotary : public IhmInterface {

    public:
        Rotary(InputInterface *inputA, InputInterface *inputB);
        Rotary(InputInterface *inputA, InputInterface *inputB, RotaryEvent *event);
        bool loop() override;
        void ping() override;

    private:
        InputInterface *_inputA;
        InputInterface *_inputB;
        RotaryEvent *_event;
        unsigned char _lastState;
        short _countEvent;
        static const unsigned char _tableState[6][4]; 
};


#endif