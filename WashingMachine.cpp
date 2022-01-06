
#include "WashingMachine.h"
#include "Laundromat.h"

WashingMachine::WashingMachine(float water, float power, int wsh):
waterUsed(water),
powUsed(power),
washes(wsh)
{

}

WashingMachine::~WashingMachine()
{
    std::cout << "Washing Machine Class Now  Out of Scope!" << std::endl;
}

void WashingMachine::wash()
{

}

float countChange(int coins)
{
    return coins;
}

float downTime(float timeOff)
{
    return timeOff;
}

