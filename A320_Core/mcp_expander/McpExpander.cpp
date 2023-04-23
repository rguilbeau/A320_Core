#include "McpExpander.h"

McpExpander::McpExpander()
{
    _mcp = new Adafruit_MCP23X17();
}

void McpExpander::begin(uint8_t i2c_addr)
{
    //SERIAL_PRINT(F("Connect to mcp1"));
    while(!_mcp->begin_I2C(i2c_addr)) {
        //SERIAL_PRINT(F("."));
    }
    //SERIAL_PRINTLN(F("."));
}

void McpExpander::setInput(uint8_t pin)
{
    _mcp->pinMode(pin, INPUT);
}

void McpExpander::setInputPullup(uint8_t pin)
{
    _mcp->pinMode(pin, INPUT_PULLUP);
}

void McpExpander::setOutput(uint8_t pin)
{
    _mcp->pinMode(pin, OUTPUT);
}

void McpExpander::loop()
{
    _allValues = _mcp->readGPIOAB();
}

unsigned char McpExpander::getValue(uint8_t pin)
{
    return bitRead(_allValues, pin);
}

void McpExpander::write(uint8_t pin, bool on)
{
    _mcp->digitalWrite(pin, on ? HIGH : LOW);
}