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
    fcuDisplayContrast = (short)frame->getData(0);
    if(fcuDisplayContrast > 100) {
        fcuDisplayContrast = 100;
    }
}