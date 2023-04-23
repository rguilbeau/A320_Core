#include "Button.h"

Button::Button(InputInterface *input)
{
    _input = input;
    _event = nullptr;
    _lastState = false;
}

Button::Button(InputInterface *input, ButtonEvent *event)
{
    _input = input;
    _event = event;
    _lastState = false;
}

bool Button::loop()
{
    bool value = _input->read();
    
    if(value && !_lastState && _event != nullptr) {
        _lastState = value;
        _event->onClick();
        return true;
    } else {
        _lastState = value;
        return false;
    }
}