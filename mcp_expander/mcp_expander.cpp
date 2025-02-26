#include "mcp_expander.hpp"

McpExpander::McpExpander()
{
    m_pMcp = new Adafruit_MCP23X17();
}

McpExpander::~McpExpander()
{
    delete m_pMcp;
    m_pMcp = 0;
}

void McpExpander::begin(const uint8_t &nI2cAddress)
{
    while(!m_pMcp->begin_I2C(nI2cAddress)) 
    { }
}

void McpExpander::setInput(const uint8_t &nPin)
{
    m_pMcp->pinMode(nPin, INPUT);
}

void McpExpander::setInputPullup(const uint8_t &nPin)
{
    m_pMcp->pinMode(nPin, INPUT_PULLUP);
}

void McpExpander::setOutput(const uint8_t &nPin)
{
    m_pMcp->pinMode(nPin, OUTPUT);
}

void McpExpander::loop()
{
    m_allValues = m_pMcp->readGPIOAB();
}

uint8_t McpExpander::getValue(const uint8_t &nPin)
{
    return bitRead(m_allValues, nPin);
}

void McpExpander::write(const uint8_t &nPin, const bool &bIsOn)
{
    m_pMcp->digitalWrite(nPin, bIsOn ? HIGH : LOW);
}