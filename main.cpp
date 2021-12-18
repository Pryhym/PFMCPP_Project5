/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        // even though I chose the name 'memberFunc' for this function, you should NAME THINGS WHAT THEY ARE OR WHAT THEY DO.
        void memberFunc() 
        { 
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
        }  
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

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
