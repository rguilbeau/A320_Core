#ifndef A320_CORE_MCP_EXPANDER_INPUT_H
#define A320_CORE_MCP_EXPANDER_INPUT_H

#include "Arduino.h"
#include "input/input_interface.hpp"
#include "mcp_expander/mcp_expander.hpp"

class McpExpanderInput : public InputInterface 
{
public:
    explicit McpExpanderInput(McpExpander *pMcp, uint8_t nPin);
    virtual ~McpExpanderInput() = default;

    bool read() override;

private:
    McpExpander *m_pMcp;
    uint8_t m_nPin;
};

#endif