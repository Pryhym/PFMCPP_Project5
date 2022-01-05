#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct Speakers
{
    std::string brand {"Vagnavox"};
    int modelNum {214375};
    int size = 12;
    int time = 0;
    float freqRange = 15000.00f;
    float impedence = 59.45f;
    
    Speakers();
    ~Speakers()
    {
        std::cout << "Destroying Speaker Constructor!" << std::endl;
    }
    
    void produceAudio();
    void receiveSignal();
    void vibrateCone();
    void displayImpedence();
    JUCE_LEAK_DETECTOR(Speakers)
};
