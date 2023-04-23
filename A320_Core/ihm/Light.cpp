#include "Light.h"

Light::Light(OutputInterface *output)
{
    _output = output;
    _state = false;
}

void Light::on(bool isOn)
{
    _state = isOn;
    _output->write(_state);
}

void Light::force(bool isOn)
{
    _output->write(isOn);
}

void Light::disableForce()
{
    _output->write(_state);
}