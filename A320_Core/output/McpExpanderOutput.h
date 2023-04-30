#ifndef A320_CORE_MCP_EXPANDER_OUTPUT_H
#define A320_CORE_MCP_EXPANDER_OUTPUT_H

#include "Arduino.h"
#include "A320_Core/output/OutputInterface.h"
#include "A320_Core/mcp_expander/McpExpander.h"

class McpExpanderOutput: public OutputInterface {

public:
    McpExpanderOutput(McpExpander *mcp, uint8_t pin);

    void write(bool on) override;

private:
    McpExpander *_mcp;
    uint8_t _pin;

};

#endif