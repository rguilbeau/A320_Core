#include "LightIndicatorsFrame.h"

/**
 * @brief Construction d'une nouvelle frame pour la gestion du mode test
 * 
 */
LightIndicatorsFrame::LightIndicatorsFrame()
{

}

/**
 * @brief Décode la frame du CAN Bus en frame utilisable via les données membres
 * 
 * @param frame 
 */
void LightIndicatorsFrame::decode(Frame *frame)
{
    isTestLight = frame->getBinary(0, 0);
}