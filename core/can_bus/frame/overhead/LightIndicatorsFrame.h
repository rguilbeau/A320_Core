#ifndef FCU_LIGHT_INDICTORS_FRAME
#define FCU_LIGHT_INDICTORS_FRAME

#include "Arduino.h"
#include "core/can_bus/Frame.h"

class LightIndicatorsFrame {

    public:

        LightIndicatorsFrame();

        void decode(Frame *frame);

        bool isTestLight;
};

#endif