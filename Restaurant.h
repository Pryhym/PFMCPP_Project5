#pragma once
#include "LeakedObjectDetector.h"

struct Restaurant
{
    int tblsAvail {9};
    int workers;
    int platesServed {24};
    float amFoodPerFamily = 79.48f;
    float hoursWorked = 86.77f;
    float amountPerTable;

    Restaurant();
    ~Restaurant(); 

    void tableAmount(int platePerFamily, int families);
    void serveFood();
    float collectPayment(float payment);
    void provideEatingUtensils();
    void displayPlatesServed();
    JUCE_LEAK_DETECTOR(Restaurant)
};
