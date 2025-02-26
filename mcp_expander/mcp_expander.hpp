#ifndef A320_CORE_MCP_EXPANDER_H
#define A320_CORE_MCP_EXPANDER_H

#include "Arduino.h"
#include <Adafruit_MCP23X17.h>

class McpExpander 
{
public:
    explicit McpExpander();
    virtual ~McpExpander();

    void begin(const uint8_t &nI2cAddress);
    void loop();

    uint8_t getValue(const uint8_t &nPin);
    void write(const uint8_t &nPin, const bool &bIsOn);
    
    void setOutput(const uint8_t &nPin);
    void setInput(const uint8_t &nPin);
    void setInputPullup(const uint8_t &nPin);

private:
    Adafruit_MCP23X17 *m_pMcp;
    uint16_t m_allValues;
};

#endif