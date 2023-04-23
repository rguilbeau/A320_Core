#ifndef FCU_DISPLAY_FRAME
#define FCU_DISPLAY_FRAME

#include "Arduino.h"
#include "core/can_bus/Frame.h"

class FcuDisplayFrame {

    public:
        static const unsigned int ID = 0x101;

        FcuDisplayFrame();

        void decode(Frame *frame);
        

        bool isMachSpeed;
        bool isTrackMode;
        bool isLatNavigation;
        bool isFpa;
        bool isSpeedDot;
        bool isHeadingDot;
        bool isAltitudeDot;
        bool isVerticalSpeedPositive;
        bool isPowerOn;
    
        float speed;
        unsigned short heading;

        int altitude;

        float verticalSpeed;
        bool isSpeedDash;
        bool isHeadingDash;
        bool isAltitudeDash;
        bool isVerticalSpeedDash;
};

#endif