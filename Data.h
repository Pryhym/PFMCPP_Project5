#pragma once
#include "LeakedObjectDetector.h"
#include "Laundromat.h"
#include "Restaurant.h"
#include "Speaker.h"
#include "WashingMachine.h"

struct Data
{
    Laundromat equipment;
    Restaurant personal;
    Speakers parts;
    WashingMachine components;

    Data();
    ~Data(){}
    
    void collectLaundromatData();
    void collectRestaurantData();
    void displayWorkers();
    JUCE_LEAK_DETECTOR(Data)
};
