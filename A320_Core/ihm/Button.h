#ifndef A320_BUTTON_H
#define A320_BUTTON_H

#include "Arduino.h"
#include "core/ihm/IhmInterface.h"
#include "core/input/InputInterface.h"
#include "core/event/ButtonEvent.h"

class Button : public IhmInterface {

    public:
        Button(InputInterface *input);
        Button(InputInterface *input, ButtonEvent *event);

        bool loop() override;

    private:
        InputInterface *_input;
        ButtonEvent *_event;
        bool _lastState;
};

#endif