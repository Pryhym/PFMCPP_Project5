/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */


#include <iostream>
#include "LeakedObjectDetector.h"
#include "Wrapper.h"
#include "Laundromat.h"
#include "Restaurant.h"
#include "Speaker.h"
#include "Server.h"
#include "Equipment.h"
#include "Data.h"

int main()
{
    LaundromatWrapper LaundromatWrapper(new Laundromat(5, 8));
    LaundromatWrapper.pointerToLaundromat->washClothes();
    LaundromatWrapper.pointerToLaundromat->dryClothes();
    std::cout << std::endl;
    //task function and cout
    std::cout << "The Amount of Water used Daily is " << LaundromatWrapper.pointerToLaundromat->amOfWaterUsedDaily << " Gallons." << std::endl;
    LaundromatWrapper.pointerToLaundromat->displayWaterUsed();
    std::cout << std::endl;

    RestaurantWrapper RestaurantWrapper(new Restaurant());
    RestaurantWrapper.pointsToRestaurant->tableAmount(3,1);
    std::cout << std::endl;
    //task function and cout
    std::cout << "The Restaurant has " << RestaurantWrapper.pointsToRestaurant->platesServed << " Plates Served.." << std::endl;
    RestaurantWrapper.pointsToRestaurant->displayPlatesServed();
    std::cout << std::endl;

    SpeakerWrapper SpeakerWrapper(new Speakers());
    SpeakerWrapper.pointsToSpeaker->receiveSignal();
    SpeakerWrapper.pointsToSpeaker->produceAudio();
    SpeakerWrapper.pointsToSpeaker->vibrateCone();
    std::cout << std::endl;
    //task function and cout
    std::cout << "The Impedence of the Speaker is " << SpeakerWrapper.pointsToSpeaker->impedence << " Ohms.." << std::endl;
    SpeakerWrapper.pointsToSpeaker->displayImpedence();
    std::cout << std::endl;
    
    EquipmentWrapper EquipmentWrapper(new Equipment());
    EquipmentWrapper.pointsToEquipment->countLaundromatEquipment();
    EquipmentWrapper.pointsToEquipment->countRestaurantEquipment();
    EquipmentWrapper.pointsToEquipment->countSpeakerEquipment();
    std::cout << std::endl;
    //task function and cout
    std::cout << "The Company has " << EquipmentWrapper.pointsToEquipment->numHeavyMachines << " Machines.." << std::endl;
    EquipmentWrapper.pointsToEquipment->displayHeavyMachines();
    std::cout << std::endl;
    
    DataWrapper DataWrapper(new Data());
    DataWrapper.pointsToData->collectLaundromatData();
    DataWrapper.pointsToData->collectRestaurantData();
    std::cout << std::endl;
    //task function and cout
    std::cout << "There are " << DataWrapper.pointsToData->personal.workers << " People working at the Restaurant.." << std::endl;
    DataWrapper.pointsToData->displayWorkers();
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
