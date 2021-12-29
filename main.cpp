/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by const reference.
*/
#if false
void someMemberFunction(const Axe& axe);
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




#include <iostream>
#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */
struct Laundromat
{
    int numWashers;
    int numDryers; 
    float amOfWaterUsedDaily {20.5f}; 
    float amOfEnergyUsedDaily = 70.21f;
    float amOfMoneyMadeDaily = 500.75f;

    struct WashingMachine
    {
        std::string brand = "Maytag";
        int modelNum;
        float waterUsed;
        float powUsed;
        int washes;
        WashingMachine(float water, float power, int wsh);
        ~WashingMachine()
        {
            std::cout << "Destroying Washing Machine Constuctor!" << std::endl;
        } 
        void wash(); 
        float countChange(int coins);
        float downTime(float timeOff);
    };

    Laundromat(int wash, int dryers);
    ~Laundromat()
    {
        std::cout << "Destorying Laundromat constructor!" << std::endl;
    }

    void waterShutOff();
    void washClothes();
    void dryClothes();
    float makeChange(float price, float amPaid);  
    void displayWaterUsed(); 
    JUCE_LEAK_DETECTOR(Laundromat)
};

Laundromat::Laundromat(int wash, int dryers) :
numWashers (wash),
numDryers (dryers)
{
    std::cout << "Laundromat Class" << std::endl;
   
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
Laundromat::WashingMachine::WashingMachine(float water, float power, int wsh):
waterUsed(water),
powUsed(power),
washes(wsh)
{

}
void Laundromat::WashingMachine::wash()
{

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

float countChange(int coins)
{
    return coins;
}

float downTime(float timeOff)
{
    return timeOff;
}

struct LaundromatWrapper
{
    LaundromatWrapper(Laundromat* ptr): pointerToLaundromat(ptr) {}
    ~LaundromatWrapper()
    {
        delete pointerToLaundromat;
    }
    Laundromat* pointerToLaundromat = nullptr;
};
/*
 copied UDT 2:
 */
struct Restaurant
{
    int tblsAvail {9};
    int workers;
    int platesServed {24};
    float amFoodPerFamily = 79.48f;
    float hoursWorked = 86.77f;
    float amountPerTable;

    Restaurant();
    ~Restaurant()
    {
        std::cout << "Destorying Restaurant Contructor!" << std::endl;
    }

    struct Server
    {
        std::string name = "James";
        long phoneNum = 8434305954;
        int amOfPeopleServed;
        float hoursWorked;
       
        Server():
        amOfPeopleServed(8),
        hoursWorked(17.5f)
        {
            std::cout << "Server Class Constructed!" << std::endl;
        }
        ~Server()
        {
            std::cout << "Destroying Server Constructor!" << std::endl;
        }

        float currPay = 9.45f;
        void serveCustomer();
        void cleanTable();
        float countTip(float tip);
    };

    void tableAmount(int platePerFamily, int families);
    void serveFood();
    float collectPayment(float payment);
    void provideEatingUtensils();
    void displayPlatesServed();
    JUCE_LEAK_DETECTOR(Restaurant)
};

Restaurant::Restaurant():
workers(8)
{
    std::cout << "Restaurant Class" << std::endl;
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

void Restaurant::Server::serveCustomer()
{

}

void Restaurant::Server::cleanTable()
{

}

float Restaurant::Server::countTip(float tip)
{
    return tip;
}

struct RestaurantWrapper
{
    RestaurantWrapper(Restaurant* ptr): pointsToRestaurant(ptr){}
    ~RestaurantWrapper()
    {
        delete pointsToRestaurant;
    }
    Restaurant* pointsToRestaurant = nullptr;
};

/*
 copied UDT 3:
 */
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

Speakers::Speakers():
size(),
freqRange()
{
    std::cout << "Speakers Class Created" << std::endl;
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

struct SpeakerWrapper
{
    SpeakerWrapper(Speakers* ptr): pointsToSpeaker(ptr){}
    ~SpeakerWrapper()
    {
        delete pointsToSpeaker;
    }
    Speakers* pointsToSpeaker = nullptr;
};
/*
 new UDT 4:
 with 2 member functions
 */
struct Equipment
{
    Laundromat machine;
    Laundromat::WashingMachine pipe;
    Restaurant dishWasher;
    Restaurant::Server carrier;
    Speakers tweaters;
    int heavyMachines = this->machine.numWashers + this->machine.numDryers;

    Equipment();
    ~Equipment()
    {
        std::cout << "Equipment Class Destroyed!" << std::endl;
    }

    void countLaundromatEquipment();
    void countRestaurantEquipment();
    void countSpeakerEquipment();
    void displayHeavyMachines();
    JUCE_LEAK_DETECTOR(Equipment)
};
Equipment::Equipment():
machine(20, 34),
pipe(24.3f, 43.1f, 9),
dishWasher(),
carrier(),
tweaters()
{
    
    std::cout << "Equipment Class Created " << std::endl;
}

void Equipment::displayHeavyMachines()
{
     std::cout << "The Company has " << this->heavyMachines << " Machines.." << std::endl;
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

struct EquipmentWrapper
{
    EquipmentWrapper(Equipment* ptr): pointsToEquipment(ptr){}
    ~EquipmentWrapper()
    {
        delete pointsToEquipment;
    }
    Equipment* pointsToEquipment = nullptr;
};
/*
 new UDT 5:
 with 2 member functions
 */
struct Data
{
    Laundromat equipment;
    Restaurant personal;
    Speakers parts;
    Laundromat::WashingMachine components;

    Data();
    ~Data()
    {
        std::cout << "Data Class Destroyed!" << std::endl;
    }
    
    void collectLaundromatData();
    void collectRestaurantData();
    void displayWorkers();
    JUCE_LEAK_DETECTOR(Data)
};

Data::Data():
equipment(24, 32),
personal(),
parts(),
components(624.54f, 215.34f, 12)
{
    std::cout << "Data Class Constructed!" << std::endl;
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

struct DataWrapper
{
    DataWrapper(Data* ptr): pointsToData(ptr){}
    ~DataWrapper()
    {
        delete pointsToData;
    }
    Data* pointsToData =nullptr;
};
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
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
    std::cout << "The Company has " << EquipmentWrapper.pointsToEquipment->heavyMachines << " Machines.." << std::endl;
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
