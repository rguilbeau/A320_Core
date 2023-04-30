#ifndef A320_CORE_CANBUS_FRAME_H
#define A320_CORE_CANBUS_FRAME_H

#include "Arduino.h"

class Frame
{

public:
    Frame(unsigned long id, uint8_t size);

    void setData(uint8_t position, unsigned char data);
    
    unsigned long getId();
    uint8_t getSize();
    unsigned char getData(uint8_t position);
    bool getBinary(uint8_t dataPosition, uint8_t binaryPosition);

private:
    unsigned long _id;
    uint8_t _size;
    unsigned char _data[8] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
};

#endif