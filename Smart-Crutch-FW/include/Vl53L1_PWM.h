#ifndef VL53L1_PWM_H
#define VL53L1_PWM_H

#include <mbed.h>

class Vl53L1_PWM
{
private:
    InterruptIn _pin;
    Timer t;
    volatile uint16_t range;
    void rise();
    void fall();
public:
    Vl53L1_PWM(PinName _p);
    ~Vl53L1_PWM();
    uint16_t getRange();
};

Vl53L1_PWM::Vl53L1_PWM(PinName _p): _pin(_p)
{
    _pin.rise(this, &Vl53L1_PWM::rise);
    _pin.fall(this, &Vl53L1_PWM::fall);
}

Vl53L1_PWM::~Vl53L1_PWM()
{
}

void Vl53L1_PWM::rise()
{
    t.reset();
    t.start();
}

void Vl53L1_PWM::fall()
{
    range = t.read_us() / 10;
    t.stop();
}

uint16_t Vl53L1_PWM::getRange()
{
    return range;
}

#endif