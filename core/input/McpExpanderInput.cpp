#include "McpExpanderInput.h"

McpExpanderInput::McpExpanderInput(McpExpander *mcp, uint8_t pin)
{
    _pin = pin;
    _mcp = mcp;
    _mcp->setInput(pin);
}

bool McpExpanderInput::read()
{
    return _mcp->getValue(_pin);
}