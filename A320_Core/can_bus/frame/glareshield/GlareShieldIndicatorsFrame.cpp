#include "GlareshieldIndicatorsFrame.h"

/**
 * @brief Construction d'une nouvelle frame pour les afficheurs du FCU
 * 
 */
GlareshieldIndicatorsFrame::GlareshieldIndicatorsFrame()
{
}

/**
 * @brief Décode la frame du CAN Bus en frame utilisable via les données membres
 * 
 * @param frame 
 */
void GlareshieldIndicatorsFrame::decode(Frame *frame)
{
    ap1 = frame->getBinary(0, 0);
    ap2 = frame->getBinary(0, 1);
    athr = frame->getBinary(0, 2);
    loc = frame->getBinary(0, 3);
    exped = frame->getBinary(0, 4);
    appr = frame->getBinary(0, 5);
}