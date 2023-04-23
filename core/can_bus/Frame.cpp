#include "Frame.h"

Frame::Frame(unsigned long id, uint8_t size)
{
    _id = id;
    _size = size;

    for(int i = 0; i < _size; i++) {
        _data[i] = 0x0;
    }
}

void Frame::setData(uint8_t position, unsigned char data)
{
    _data[position] = data;
} 

unsigned long Frame::getId()
{
    return _id;
}

uint8_t Frame::getSize()
{
    return _size;
}

unsigned char Frame::getData(uint8_t position)
{
    if(position <= 8) {
        return _data[position];
    } else {
        return 0x0;
    }
}

bool Frame::getBinary(uint8_t dataPosition, uint8_t binaryPosition)
{
    if(dataPosition <= 8 && binaryPosition <= 8) {
        unsigned char data = _data[dataPosition];
        for(int i = 7 ; i >= 0 ; i--) {
            if(pow(2, i) <= data) {
                data = data - pow(2, i);
                if(8-(i+1) == binaryPosition) {
                    return true;
                } 
            }
        }
    }
    
    return false;
}