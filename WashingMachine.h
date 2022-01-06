#pragma once
#include <iostream>

struct WashingMachine
    {
        std::string brand = "Maytag";
        int modelNum;
        float waterUsed;
        float powUsed;
        int washes;
        WashingMachine(float water, float power, int wsh);
        ~WashingMachine(){} 
        
        void wash(); 
        float countChange(int coins);
        float downTime(float timeOff);
    };





