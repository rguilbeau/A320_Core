#ifndef A320_MCP_EXPANDER_INPUT_H
#define A320_MCP_EXPANDER_INPUT_H

#include "Arduino.h"
#include "A320_Core/input/InputInterface.h"
#include "A320_Core/mcp_expander/McpExpander.h"

class McpExpanderInput : public InputInterface {

    public:
        McpExpanderInput(McpExpander *mcp, uint8_t pin);
        bool read() override;

    private:
        McpExpander *_mcp;
        uint16_t _pin;
};

#endif