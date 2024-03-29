#ifndef A320_CORE_SWITCH_H
#define A320_CORE_SWITCH_H

#include "Arduino.h"
#include "A320_Core/input/InputInterface.h"
#include "A320_Core/ihm/IhmInterface.h"
#include "A320_Core/event/SwitchEvent.h"

class Switch : public IhmInterface {

    public:
        Switch(InputInterface *input);
        Switch(InputInterface *input, SwitchEvent *event);

        bool loop() override;
        void ping() override;

    private:
        InputInterface *_input;
        SwitchEvent *_event;
        bool _lastValue;
};

#endif