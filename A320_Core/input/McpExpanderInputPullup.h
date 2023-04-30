#ifndef A320_CORE_MCP_EXPANDER_INPUT_PULLUP_H
#define A320_CORE_MCP_EXPANDER_INPUT_PULLUP_H

#include "Arduino.h"
#include "A320_Core/input/InputInterface.h"
#include "A320_Core/mcp_expander/McpExpander.h"

class McpExpanderInputPullup : public InputInterface {

    public:
        McpExpanderInputPullup(McpExpander *mcp, uint8_t pin);
        bool read() override;

    private:
        McpExpander *_mcp;
        uint16_t _pin;
};

#endif