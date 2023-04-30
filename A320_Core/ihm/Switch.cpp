#include "Switch.h"

Switch::Switch(InputInterface *input)
{
    _input = input;
    _lastValue = false;
    _event = nullptr;
}

Switch::Switch(InputInterface *input, SwitchEvent *event)
{
    _input = input;
    _lastValue = false;
    _event = event;
}

bool Switch::loop()
{
    bool value = _input->read();
    
    if(_lastValue != value && _event != nullptr) {
        _lastValue = value;
        _event->onChange(value);
        return true;
    }

    return false;
}

void Switch::ping()
{
    if(_event != nullptr) {
        _event->onPing(_lastValue);
    }
}