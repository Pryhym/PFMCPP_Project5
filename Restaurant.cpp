#include "Restaurant.h"

Restaurant::Restaurant():
workers(8)
{
    std::cout << "Restaurant Class" << std::endl;
}

Restaurant::~Restaurant()
{
    std::cout << "Restaurant Class Now  Out of Scope!" << std::endl;
}

void Restaurant::displayPlatesServed()
{
     std::cout << "The Restaurant has " << this->platesServed << " Plates Served.." << std::endl;
}

void Restaurant::serveFood()
{
    
}

float Restaurant::collectPayment(float payment)
{
    return payment;
}

void Restaurant::provideEatingUtensils()
{

}

void Restaurant::tableAmount(int platePerFamily, int families)
{
    while (families < platesServed) 
    {
        amountPerTable += (platePerFamily * this->amFoodPerFamily);
        std::cout << "The Amount Of food served Total Is: " << this->amountPerTable << std::endl;
        ++families;
    }
    std::cout << std::endl;
}
