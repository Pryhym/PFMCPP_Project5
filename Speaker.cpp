#include "Speaker.h"

Speakers::Speakers():
size(),
freqRange()
{
    std::cout << "Speakers Class Created" << std::endl;
}

Speakers::~Speakers()
{
    std::cout << "Speakers Class Now  Out of Scope!" << std::endl;
}

void Speakers::produceAudio()
{
    while (time < 2)
    {
        std::cout << "Producing Audio!!!!!!!" << std::endl;
        ++this->time;
    }
    std::cout << std::endl;
}

void Speakers::displayImpedence()
{
    std::cout << "The Impedence of the Speaker is " << this->impedence << " Ohms.." << std::endl;
}

void Speakers::receiveSignal()
{
    std::cout << "Model Number: " << this->modelNum << std::endl;
}

void Speakers::vibrateCone()
{
    
}
