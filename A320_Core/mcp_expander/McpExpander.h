#ifndef A320_CORE_MCP_EXPANDER_H
#define A320_CORE_MCP_EXPANDER_H

#include "Arduino.h"
#include "Adafruit_MCP23X17.h"

class McpExpander {

    public:
        McpExpander();

        void begin(uint8_t i2c_addr);
        void loop();
        unsigned char getValue(uint8_t pin);
        void write(uint8_t pin, bool on);
        void setOutput(uint8_t pin);
        void setInput(uint8_t pin);
        void setInputPullup(uint8_t pin);

    private:
        Adafruit_MCP23X17 *_mcp;
        uint16_t _allValues;

};

#endif