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
    segmentsScreens = frame->getData(0);
    glareshieldPanel = frame->getData(1);
    overheadPanel = frame->getData(2);
    pedestalPanel = frame->getData(3);
    indicators = frame->getData(4);
    buttons = frame->getData(5);
}