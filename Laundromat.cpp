
#include <iostream>
#include "Laundromat.h"

Laundromat::Laundromat(int wash, int dryers) :
numWashers (wash),
numDryers (dryers)
{
    std::cout << "Laundromat Class" << std::endl;
   
}

Laundromat::~Laundromat()
{
    std::cout << "Destroying Laundromat Constuctor!" << std::endl;
}

void Laundromat::washClothes()
{
    std::cout << "Number Of Dryers: " << this->numDryers << std::endl;
    std::cout << std::endl;
}

void Laundromat::dryClothes()
{

}

void Laundromat::displayWaterUsed()
{
    std::cout << "The Amount of Water used Daily is " << this->amOfWaterUsedDaily << " Gallons." << std::endl;
}

float Laundromat::makeChange(float price, float amPaid)
{
    return amPaid - price;
}

void Laundromat::waterShutOff()
{

    while(amOfWaterUsedDaily < 200)
    {
        std::cout << "Amount Of Water Used: " << this->amOfWaterUsedDaily <<std::endl;
        amOfWaterUsedDaily += 12.43f;
    }
    std::cout << std::endl;            
    std::cout << "Water Exceeded Daily Amount!" << std::endl;
    std::cout << std::endl;
}
