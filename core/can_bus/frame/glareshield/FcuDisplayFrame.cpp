#include "FcuDisplayFrame.h"

/**
 * @brief Construction d'une nouvelle frame pour les afficheurs du FCU
 * 
 */
FcuDisplayFrame::FcuDisplayFrame()
{
}

/**
 * @brief Décode la frame du CAN Bus en frame utilisable via les données membres
 * 
 * @param frame 
 */
void FcuDisplayFrame::decode(Frame *frame)
{
    isMachSpeed = frame->getBinary(3, 0);
    isTrackMode = frame->getBinary(3, 1);
    isLatNavigation = frame->getBinary(3, 2);
    isFpa = frame->getBinary(3, 3);
    isSpeedDot = frame->getBinary(3, 4);
    isHeadingDot = frame->getBinary(3, 5);
    isAltitudeDot = frame->getBinary(3, 6);
    isVerticalSpeedPositive = frame->getBinary(3, 7);

    speed = frame->getData(0);
    heading = frame->getData(1);

    for(short i = 0; i < 5; i++) {
        if(frame->getBinary(2, i) == true) {
            speed = speed + ((i + 1) * 100);
            break;
        }
    }

    for(short i = 5; i < 8; i++) {
        if(frame->getBinary(2, i) == true) {
            heading = heading + ((i - 4) * 100);
            break;
        }
    }

    if(isMachSpeed) {
        speed = speed / 100;
    }

    altitude = (frame->getData(4) + frame->getData(5)) * 100;

    verticalSpeed = 0;
    if(isFpa) {
        verticalSpeed = ((float)frame->getData(6)) / 10;
    } else {
        verticalSpeed = frame->getData(6) * 100;
    }

    isSpeedDash = frame->getBinary(7, 0);
    isHeadingDash = frame->getBinary(7, 1);
    isAltitudeDash = frame->getBinary(7, 2);
    isVerticalSpeedDash = frame->getBinary(7, 3);
    isPowerOn = frame->getBinary(7, 7);
}