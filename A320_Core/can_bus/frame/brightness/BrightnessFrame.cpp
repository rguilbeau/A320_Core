#include "BrightnessFrame.h"

/**
 * @brief Construction d'une nouvelle frame pour le rétrp-éclairage des écrans
 * 
 */
BrightnessFrame::BrightnessFrame()
{

}

/**
 * @brief Décode la frame du CAN Bus en frame utilisable via les données membres
 * 
 * @param frame 
 */
void BrightnessFrame::decode(Frame *frame)
{
    testLight = frame->getBinary(0, 0);
    segmentsScreens = frame->getData(1);
    glareshieldPanel = frame->getData(2);
    overheadPanel = frame->getData(3);
    pedestalPanel = frame->getData(4);
    indicators = frame->getData(5);
    buttons = frame->getData(6);
}