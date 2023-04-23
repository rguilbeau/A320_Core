#include "McpExpanderInputPullup.h"

McpExpanderInputPullup::McpExpanderInputPullup(McpExpander *mcp, uint8_t pin)
{
    _pin = pin;
    _mcp = mcp;
    _mcp->setInputPullup(pin);
}

bool McpExpanderInputPullup::read()
{
    bool value = _mcp->getValue(_pin);
    return !value; // inversion à cause du pullup
}