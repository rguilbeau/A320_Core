#include "BrightnessPanelFrame.h"

BrightnessPanelFrame::BrightnessPanelFrame()
{

}

void BrightnessPanelFrame::decode(Frame *frame)
{
    glareshieldPanel = frame->getData(0);
    overheadPanel = frame->getData(1);
    pedestalPanel = frame->getData(2);
    indicators = frame->getData(3);
    buttons = frame->getData(4);
}