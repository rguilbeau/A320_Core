#include "mcp_expander_input.hpp"

McpExpanderInput::McpExpanderInput(McpExpander *pMcp, uint8_t nPin)
{
    m_nPin = nPin;
    m_pMcp = pMcp;
    m_pMcp->setInput(m_nPin);
}

bool McpExpanderInput::read()
{
    return m_pMcp->getValue(m_nPin);
}