#ifndef A320_CORE_MCP_EXPANDER_OUTPUT_H
#define A320_CORE_MCP_EXPANDER_OUTPUT_H

#include "Arduino.h"
#include "output/output_interface.hpp"
#include "mcp_expander/mcp_expander.hpp"

class McpExpanderOutput: public OutputInterface 
{

public:
    explicit McpExpanderOutput(McpExpander *pMcp, const uint8_t &nPin);
    virtual ~McpExpanderOutput() = default;

    void write(const bool &bIsOn) override;

private:
    McpExpander *m_pMcp;
    uint8_t m_nPin;
};

#endif