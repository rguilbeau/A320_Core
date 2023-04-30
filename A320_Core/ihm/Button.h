#ifndef A320_CORE_BUTTON_H
#define A320_CORE_BUTTON_H

#include "Arduino.h"
#include "A320_Core/ihm/IhmInterface.h"
#include "A320_Core/input/InputInterface.h"
#include "A320_Core/event/ButtonEvent.h"

class Button : public IhmInterface {

    public:
        Button(InputInterface *input);
        Button(InputInterface *input, ButtonEvent *event);

        bool loop() override;
        void ping() override;

    private:
        InputInterface *_input;
        ButtonEvent *_event;
        bool _lastState;
};

#endif