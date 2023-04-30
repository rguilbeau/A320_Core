#include "BrightnessSevenSegmentsFrame.h"


BrightnessSevenSegmentsFrame::BrightnessSevenSegmentsFrame()
{

}

void BrightnessSevenSegmentsFrame::decode(Frame *frame)
{
    isTestLight = frame->getBinary(0, 0);
    fcu = frame->getData(1);
    altimeters = frame->getData(2);
    bateries = frame->getData(3);
    radio = frame->getData(4);
}