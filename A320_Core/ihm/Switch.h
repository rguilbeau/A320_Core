#ifndef A320_SWITCH_H
#define A320_SWITCH_H

#include "Arduino.h"
#include "A320_Coreinput/InputInterface.h"
#include "A320_Coreihm/IhmInterface.h"
#include "A320_Coreevent/SwitchEvent.h"

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