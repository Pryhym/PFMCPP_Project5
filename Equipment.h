#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
#include "Laundromat.h"
#include "WashingMachine.h"
#include "Restaurant.h"
#include "Server.h"
#include "Speaker.h"

struct Equipment
{
    Laundromat machine;
    WashingMachine pipe;
    Restaurant dishWasher;
    Server carrier;
    Speakers tweaters;
    int numHeavyMachines = this->machine.numWashers + this->machine.numDryers;

    Equipment();
    ~Equipment();

    void countLaundromatEquipment();
    void countRestaurantEquipment();
    void countSpeakerEquipment();
    void displayHeavyMachines();
    JUCE_LEAK_DETECTOR(Equipment)
};
