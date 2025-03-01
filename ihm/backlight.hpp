#ifndef A320_CORE_BACKLIGHT_H
#define A320_CORE_BACKLIGHT_H

#include "output/pwm_interface.hpp"

class Backlight
{
public:
    explicit Backlight(PwmInterface *pOutput);
    virtual ~Backlight() = default;

    void set(uint8_t nValue);
    void setPower(bool const &nPowered);

private:
    PwmInterface *m_pOutput;
    uint8_t m_nValue = 0;
    bool m_bIsPowered = false;
};

#endif