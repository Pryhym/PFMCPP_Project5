#include "Equipment.h"

Equipment::Equipment():
machine(20, 34),
pipe(24.3f, 43.1f, 9)
{   
    std::cout << "Equipment Class Created " << std::endl;
}

Equipment::~Equipment(){}

void Equipment::displayHeavyMachines()
{
     std::cout << "The Company has " << this->numHeavyMachines << " Machines.." << std::endl;
}

void Equipment::countLaundromatEquipment()
{
    std::cout << "Laundromat Machines in Inventory: " << machine.numWashers << std::endl;
    std::cout << "Laundromat Dryers in Inventory: " << machine.numDryers << std::endl;
}

void Equipment::countRestaurantEquipment()
{
    std::cout << "Restaurant Workers: " << dishWasher.workers << std::endl;
    std::cout << "Amount of Server Carriers In Inventory: " << carrier.amOfPeopleServed << std::endl;
}

void Equipment::countSpeakerEquipment()
{
    std::cout << "Speaker Size: " << tweaters.size << std::endl;
    std::cout << "Speaker Frequency Range: " << tweaters.freqRange << std::endl;
}
