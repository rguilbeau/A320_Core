#include "McpExpanderOutput.h"

McpExpanderOutput::McpExpanderOutput(McpExpander *mcp, uint8_t pin)
{
    _mcp = mcp;
    _pin = pin;
    _mcp->setOutput(_pin);
}

void McpExpanderOutput::write(bool on)
{
    _mcp->write(_pin, on);
}