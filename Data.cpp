#include "Data.h"

Data::Data():
equipment(24, 32),
personal(),
parts(),
components(624.54f, 215.34f, 12)
{
    std::cout << "Data Class Constructed!" << std::endl;
}
Data::~Data()
{
    std::cout << "Destroying Data Constuctor!" << std::endl;
}

void Data::displayWorkers()
{
    std::cout << "There are " << this->personal.workers << " People working at the Restaurant.." << std::endl;
}

void Data::collectLaundromatData()
{
    int equip = equipment.numWashers * equipment.numDryers;
    std::cout << "Laundromat Equipment Amount: " << equip << std::endl;
}

void Data::collectRestaurantData()
{
    std::cout << "Restraurant Personal working: " << personal.workers << std::endl;
}
