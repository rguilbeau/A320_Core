#ifndef A320_SWITCH_H
#define A320_SWITCH_H

#include "Arduino.h"
#include "core/input/InputInterface.h"
#include "core/ihm/IhmInterface.h"
#include "core/event/SwitchEvent.h"

class Switch : public IhmInterface {

    public:
        Switch(InputInterface *input);
        Switch(InputInterface *input, SwitchEvent *event);

        bool loop() override;

    private:
        InputInterface *_input;
        SwitchEvent *_event;
        bool _lastValue;
};

#endif