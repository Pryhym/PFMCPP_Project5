#pragma once
#include <iostream>
#include <memory>

struct WashingMachine
    {
        std::string brand = "Maytag";
        int modelNum;
        float waterUsed;
        float powUsed;
        int washes;
        WashingMachine(float water, float power, int wsh);
        ~WashingMachine()
        {
            std::cout << "Destroying Washing Machine Constuctor!" << std::endl;
        } 
        void wash(); 
        float countChange(int coins);
        float downTime(float timeOff);
    };