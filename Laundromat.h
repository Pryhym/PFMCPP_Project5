#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"


struct Laundromat
{
    int numWashers;
    int numDryers; 
    float amOfWaterUsedDaily {20.5f}; 
    float amOfEnergyUsedDaily = 70.21f;
    float amOfMoneyMadeDaily = 500.75f;

    

    Laundromat(int wash, int dryers);
    ~Laundromat();

    void waterShutOff();
    void washClothes();
    void dryClothes();
    float makeChange(float price, float amPaid);  
    void displayWaterUsed(); 
    JUCE_LEAK_DETECTOR(Laundromat)
};
