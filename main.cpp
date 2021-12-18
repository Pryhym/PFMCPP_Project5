/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 */
#include <iostream>
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
};

Laundromat::Laundromat(int wash, int dryers) :
numWashers (wash),
numDryers (dryers)
{
    std::cout << "Laundromat Class" << std::endl;
    std::cout << "constructing the Amount of Water Used is: " << amOfWaterUsedDaily << std::endl;
}
void Laundromat::washClothes()
{
    std::cout << "Number Of Dryers: " << numDryers << std::endl;
    std::cout << std::endl;
}

void Laundromat::dryClothes()
{

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
    amOfWaterUsedDaily = 0;
    while(amOfWaterUsedDaily < 200)
    {
        std::cout << "Amount Of Water Used: " << amOfWaterUsedDaily <<std::endl;
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
};

Restaurant::Restaurant():
workers(8)
{
    std::cout << "Restaurant Class" << std::endl;
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
        amountPerTable += (platePerFamily * amFoodPerFamily);
        std::cout << "The Amount Of food served Total Is: " << amountPerTable << std::endl;
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
        ++time;
    }
    std::cout << std::endl;
}

void Speakers::receiveSignal()
{
    std::cout << "Model Number: " << modelNum << std::endl;
}

void Speakers::vibrateCone()
{
    
}
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

    Equipment();
    ~Equipment()
    {
        std::cout << "Equipment Class Destroyed!" << std::endl;
    }

    void countLaundromatEquipment();
    void countRestaurantEquipment();
    void countSpeakerEquipment();
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
};

Data::Data():
equipment(24, 32),
personal(),
parts(),
components(624.54f, 215.34f, 12)
{
    std::cout << "Data Class Constructed!" << std::endl;
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
    Laundromat device(54, 40);
    device.washClothes();
    device.dryClothes();
    std::cout << std::endl;

    Restaurant food;
    food.tableAmount(3,1);
    std::cout << std::endl;

    Speakers speak;
    speak.receiveSignal();
    speak.produceAudio();
    speak.vibrateCone();
    std::cout << std::endl;

    Equipment hardware;
    hardware.countLaundromatEquipment();
    hardware.countRestaurantEquipment();
    hardware.countSpeakerEquipment();
    std::cout << std::endl;

    Data numbers;
    numbers.collectLaundromatData();
    numbers.collectRestaurantData();
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
