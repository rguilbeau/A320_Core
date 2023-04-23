#ifndef A320_MCP_EXPANDER_INPUT_PULLUP_H
#define A320_MCP_EXPANDER_INPUT_PULLUP_H

#include "Arduino.h"
#include "A320_Coreinput/InputInterface.h"
#include "A320_Coremcp_expander/McpExpander.h"

class McpExpanderInputPullup : public InputInterface {

    public:
        McpExpanderInputPullup(McpExpander *mcp, uint8_t pin);
        bool read() override;

    private:
        McpExpander *_mcp;
        uint16_t _pin;
};

#endif