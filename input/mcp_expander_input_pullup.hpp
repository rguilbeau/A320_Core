#ifndef A320_CORE_MCP_EXPANDER_INPUT_PULLUP_H
#define A320_CORE_MCP_EXPANDER_INPUT_PULLUP_H

#include "Arduino.h"
#include "input/input_interface.hpp"
#include "mcp_expander/mcp_expander.hpp"

class McpExpanderInputPullup : public InputInterface 
{

public:
    explicit McpExpanderInputPullup(McpExpander *pMcp, uint8_t nPin);
    virtual ~McpExpanderInputPullup() = default;

    bool read() override;

private:
    McpExpander *m_pMcp;
    uint8_t m_nPin;
};

#endif