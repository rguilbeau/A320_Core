#include "mcp_expander_output.hpp"

McpExpanderOutput::McpExpanderOutput(McpExpander *pMcp, const uint8_t &nPin)
{
    m_pMcp = pMcp;
    m_nPin = nPin;
    m_pMcp->setOutput(m_nPin);
}

void McpExpanderOutput::write(const bool &bIsOn)
{
    m_pMcp->write(m_nPin, bIsOn);
}