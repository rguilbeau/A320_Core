#ifndef A320_CORE_LIGHT_H
#define A320_CORE_LIGHT_H

#include "Arduino.h"
#include "A320_Core/output/OutputInterface.h"

class Light {

public:
    Light(OutputInterface *output);

    void on(bool isOn);
    void force(bool isOn);
    void disableForce();

private:
    OutputInterface *_output;
    bool _state;
};

#endif