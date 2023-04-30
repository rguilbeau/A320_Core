#include "BrightnessPanelFrame.h"

BrightnessPanelFrame::BrightnessPanelFrame()
{

}

void BrightnessPanelFrame::decode(Frame *frame)
{
    fcuDisplay = frame->getData(0);
    glareshieldPanel = frame->getData(1);
    overheadPanel = frame->getData(2);
    pedestalPanel = frame->getData(3);
    indicators = frame->getData(4);
    buttons = frame->getData(5);
}