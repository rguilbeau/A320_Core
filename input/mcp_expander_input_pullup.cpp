#include "mcp_expander_input_pullup.hpp"

McpExpanderInputPullup::McpExpanderInputPullup(McpExpander *pMcp, uint8_t nPin)
{
    m_nPin = nPin;
    m_pMcp = pMcp;
    m_pMcp->setInputPullup(m_nPin);
}

bool McpExpanderInputPullup::read()
{
    bool bValue = m_pMcp->getValue(m_nPin);
    return !bValue; // inversion à cause du pullup
}